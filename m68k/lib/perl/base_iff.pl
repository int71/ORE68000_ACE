##############################################################################
##																			##
##																			##
##									OFW										##
##																			##
##	'base_iff.pl'									2024 written by int71	##
##############################################################################

use strict;
require 'base.pl';
require 'base_image.pl';

#	IFFFile		::= FORM | LIST | CAT
#	Chunk		::= ID #{ UBYTE* } [0]
#	FORM		::= "FORM" #{ ID (Chunk | FORM | LIST | CAT)* }
#	CAT			::= "CAT " #{ ID (FORM | LIST | CAT)* }
#	LIST		::= "LIST" #{ ID PROP* (FORM | LIST | CAT)* }
#	PROP		::= "PROP" #{ ID Chunk* }

{
	package BASE_IFF;

	BEGIN{
		our($Version,$Date)=('2.00','2021/03/27');
		our(%ParentType,$DefaultParentType);

		%ParentType=(
			'FORM'=>	'',
			'CAT '=>	'',
			'LIST'=>	'',
			'PROP'=>	''
		);
		$DefaultParentType='LIST';
		return;
	}

	sub new{
		my($class,$filename)=@_;
		my($this);

		$this={};
		bless($this,$class);
		$$this{'Sub'}=[];
		$$this{'Body'}=new BASE_IMAGE::();
		$this->SetType();
		if(defined $filename){
			$this->Load($filename);
		}
		return $this;
	}

	sub GetType{
		my($this)=@_;

		return ($$this{'Type'},$$this{'ID'});
	}

	sub SetType{
		my($this,$type,$id)=@_;

		$$this{'Type'}=substr($type.'    ',0,4);
		$$this{'ID'}=substr($id.'    ',0,4);
		return;
	}

	sub GetSubParent{
		my($this,$subid,$subindex)=@_;
		my($return);

		$return=$this->GetSub($subid,$subindex);
		if(defined $BASE_IFF::ParentType{$$return{'Type'}}){
			return $return;
		}else{
			my(@sub);

			@sub=split(/\//,$subid);
			$return->SetType($BASE_IFF::DefaultParentType,$sub[$#sub]);
			return $return;
		}
	}

	sub GetSub{
		my($this,$subid,$subindex)=@_;

		if(defined $subid){
			my($sub,$subrest);

			($sub,$subrest)=split(/\//,$subid,2);
			$sub=substr($sub.'    ',0,4);
			if(not defined $subrest){
				my($i,$subiff);

				$i=0;
				$subindex++;
				foreach $subiff(@{$$this{'Sub'}}){
					if(
						($$subiff{'Type'} eq $sub)||(
							(defined $BASE_IFF::ParentType{$$subiff{'Type'}})&&
							($$subiff{'ID'} eq $sub)
						)
					){
						$i++;
						if($i==$subindex){
							return $subiff;
						}
					}
				}
				for(;$i<$subindex;$i++){
					$subiff=new BASE_IFF::();
					$subiff->SetType($sub);
					$$this{'Sub'}[@{$$this{'Sub'}}]=$subiff;
				}
				return $subiff;
			}else{
				my($subiff);

				foreach $subiff(@{$$this{'Sub'}}){
					if(
						(defined $BASE_IFF::ParentType{$$subiff{'Type'}})&&
						($$subiff{'ID'} eq $sub)
					){
						return $subiff->GetSub($subrest,$subindex);
					}
				}
				$subiff=new BASE_IFF::();
				$subiff->SetType($BASE_IFF::DefaultParentType,$sub);
				$$this{'Sub'}[@{$$this{'Sub'}}]=$subiff;
				return $subiff->GetSub($subrest,$subindex);
			}
		}else{
			return @{$$this{'Sub'}};
		}
	}

	sub SetSub{
		my($this,$source)=@_;

		@{$$this{'Sub'}}=@$source;
		return;
	}

	sub GetBody{
		my($this)=@_;

		return $$this{'Body'};
	}

	sub SetBody{
		my($this,$source)=@_;

		$$this{'Body'}->Set($source);
		return;
	}

	sub GetImage{
		my($this)=@_;
		my($type,$id,$return);

		($type,$id)=$this->GetType();
		$return=new BASE_IMAGE::();
		if(defined $BASE_IFF::ParentType{$type}){
			my($sub);

			$return->SetSubBody($type);
			$return->SetDWORD_B(0);
			$return->SetSubBody($id);
			foreach $sub($this->GetSub()){
				$return->SetSub($sub->GetImage());
			}
			$return->SetDWORD_B($return->GetSize()-8,4);
		}else{
			$return->SetSubBody($type);
			$return->SetDWORD_B($$this{'Body'}->GetSize());
			$return->SetSub($$this{'Body'});
			$return->SetSize(($return->GetSize()+1)&~1);
		}
		return $return;
	}

	sub SetImage{
		my($this,$source)=@_;
		my($type,$size);

		$source->SetCurrent(0);
		$type=$source->GetSubBody(4);
		$size=$source->GetDWORD_B();
		if(defined $size){
			$this->SetImage_Body($type,$source->GetSub($size));
		}
		return;
	}

	sub SetImage_Body{
		my($this,$type,$source)=@_;

		$source->SetCurrent(0);
		if(defined $BASE_IFF::ParentType{$type}){
			my($id);

			$$this{'Sub'}=[];
			$$this{'Body'}->SetBody('');
			$this->SetType($type,$source->GetSubBody(4));
			for(;;){
				my($subtype,$subsize);

				$subtype=$source->GetSubBody(4);
				$subsize=$source->GetDWORD_B();
				if(defined $subsize){
					my($sub);

					$sub=new BASE_IFF::();
					$sub->SetImage_Body($subtype,$source->GetSub($subsize));
					$this->SetSub([$this->GetSub(),$sub]);
					$source->SetCurrent(($source->GetCurrent()+1)&~1);
				}else{
					last;
				}
			}
		}else{
			$$this{'Sub'}=[];
			$$this{'Body'}->Set($source);
			$this->SetType($type);
			return;
		}
		return;
	}

	sub Save{
		my($this,$filename)=@_;

		$this->GetImage()->Save($filename);
		return;
	}

	sub Load{
		my($this,$filename)=@_;

		$this->SetImage(new BASE_IMAGE::($filename));
		return;
	}
}

1;
