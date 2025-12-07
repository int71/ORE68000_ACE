##############################################################################
##																			##
##																			##
##									OFW										##
##																			##
##	'base_riff.pl'									2024 written by int71	##
##############################################################################

use strict;
require 'base.pl';
require 'base_image.pl';

#	RIFFFile	::= RIFF
#	Chunk		::= ID #{ UBYTE* } [0]
#	RIFF		::= "RIFF" #{ ID (Chunk | RIFF | LIST)* }
#	LIST		::= "LIST" #{ ID (Chunk | RIFF | LIST)* }

{
	package BASE_RIFF;

	BEGIN{
		our($Version,$Date)=('2.00','2021/03/27');
		our(%ParentType,$DefaultParentType);

		%ParentType=(
			'RIFF'=>	'',
			'LIST'=>	''
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
		if(defined $BASE_RIFF::ParentType{$$return{'Type'}}){
			return $return;
		}else{
			my(@sub);

			@sub=split(/\//,$subid);
			$return->SetType($BASE_RIFF::DefaultParentType,$sub[$#sub]);
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
				my($i,$subriff);

				$i=0;
				$subindex++;
				foreach $subriff(@{$$this{'Sub'}}){
					if(
						($$subriff{'Type'} eq $sub)||(
							(defined $BASE_RIFF::ParentType{$$subriff{'Type'}})&&
							($$subriff{'ID'} eq $sub)
						)
					){
						$i++;
						if($i==$subindex){
							return $subriff;
						}
					}
				}
				for(;$i<$subindex;$i++){
					$subriff=new BASE_RIFF::();
					$subriff->SetType($sub);
					$$this{'Sub'}[@{$$this{'Sub'}}]=$subriff;
				}
				return $subriff;
			}else{
				my($subriff);

				foreach $subriff(@{$$this{'Sub'}}){
					if(
						(defined $BASE_RIFF::ParentType{$$subriff{'Type'}})&&
						($$subriff{'ID'} eq $sub)
					){
						return $subriff->GetSub($subrest,$subindex);
					}
				}
				$subriff=new BASE_RIFF::();
				$subriff->SetType($BASE_RIFF::DefaultParentType,$sub);
				$$this{'Sub'}[@{$$this{'Sub'}}]=$subriff;
				return $subriff->GetSub($subrest,$subindex);
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
		if(defined $BASE_RIFF::ParentType{$type}){
			my($sub);

			$return->SetSubBody($type);
			$return->SetDWORD_L(0);
			$return->SetSubBody($id);
			foreach $sub($this->GetSub()){
				$return->SetSub($sub->GetImage());
			}
			$return->SetDWORD_L($return->GetSize()-8,4);
		}else{
			$return->SetSubBody($type);
			$return->SetDWORD_L($$this{'Body'}->GetSize());
			$return->SetSub($$this{'Body'});
			$return->SetSize(($return->GetSize()+1)&~1);
		}
		return $return;
	}

	sub SetImage{
		my($this,$type,$source)=@_;

		$source->SetCurrent(0);
		if(defined $BASE_RIFF::ParentType{$type}){
			my($id);

			$$this{'Sub'}=[];
			$$this{'Body'}->SetBody('');
			$this->SetType($type,$source->GetSubBody(4));
			for(;;){
				my($subtype,$subsize);

				$subtype=$source->GetSubBody(4);
				$subsize=$source->GetDWORD_L();
				if(defined $subsize){
					my($sub);

					$sub=new BASE_RIFF::();
					$sub->SetImage($subtype,$source->GetSub($subsize));
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
		my($image,$type,$size);

		$image=new BASE_IMAGE::($filename);
		$image->SetCurrent(0);
		$type=$image->GetSubBody(4);
		$size=$image->GetDWORD_L();
		if(defined $size){
			$this->SetImage($type,$image->GetSub($size));
		}
		return;
	}
}

1;
