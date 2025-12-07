##############################################################################
##																			##
##																			##
##									OFW										##
##																			##
##	'base_image.pl'									2024 written by int71	##
##############################################################################

use strict;

{
	package BASE_IMAGE;

	BEGIN{
		our($Version,$Date)=('2.02','2024/12/11');
		our($VARIABLERecursiveLimit)=(0);

		return;
	}

	sub new{
		my($class,$filename)=@_;
		my($this);

		$this={};
		bless($this,$class);
		$$this{'Body'}='';
		$$this{'Current'}=0;
		if(defined $filename){
			$this->Load($filename);
		}
		return $this;
	}

	sub GetBody{
		my($this)=@_;
		my($return);

		$^H|=8;
		$return=$$this{'Body'};
		$$this{'Current'}=length($$this{'Body'});
		$^H&=~8;
		return $return;
	}

	sub SetBody{
		my($this,$source)=@_;

		$^H|=8;
		$$this{'Body'}=$source;
		$$this{'Current'}=length($$this{'Body'});
		$^H&=~8;
		return;
	}

	sub AddBody{
		my($this,$source)=@_;

		$^H|=8;
		$$this{'Body'}.=$source;
		$$this{'Current'}=length($$this{'Body'});
		$^H&=~8;
		return;
	}

	sub GetSubBody{
		my($this,$size,$offset)=@_;
		my($length,$return);

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		$length=$this->GetSize();
		if($length<$offset){
			return undef;
		}
		if((not defined $size)||($length<$size+$offset)){
			$size=$length-$offset;
		}
		$^H|=8;
		$return=substr($$this{'Body'},$offset,$size);
		$$this{'Current'}=$offset+$size;
		$^H&=~8;
		return $return;
	}

	sub SetSubBody{
		my($this,$source,$size,$offset)=@_;
		my($length);

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		$length=$this->GetSize();
		if($length<$offset){
			$this->SetSize($offset);
			$length=$offset;
		}
		if((not defined $size)||($length<$size+$offset)){
			$size=$length-$offset;
		}
		$^H|=8;
		$$this{'Current'}=$offset+length($source);
		$$this{'Body'}=substr($$this{'Body'},0,$offset).$source.substr($$this{'Body'},$offset+$size);
		$^H&=~8;
		return;
	}

	sub GetCurrent{
		my($this)=@_;

		return $$this{'Current'};
	}

	sub SetCurrent{
		my($this,$current)=@_;

		if($this->GetSize()<$current){
			$this->SetSize($current);
		}
		$$this{'Current'}=$current;
		return;
	}

	sub GetSize{
		my($this)=@_;
		my($size);

		$^H|=8;
		$size=length($$this{'Body'});
		$^H&=~8;
		return $size;
	}

	sub SetSize{
		my($this,$size)=@_;
		my($diff);

		$^H|=8;
		$diff=$size-length($$this{'Body'});
		if($diff<0){
			$$this{'Body'}=substr($$this{'Body'},0,$size);
			if($size<$$this{'Current'}){
				$$this{'Current'}=$size;
			}
		}else{
			$$this{'Body'}.="\0"x$diff;
		}
		$^H&=~8;
		return;
	}

	sub Get{
		my($this)=@_;
		my($return);

		$return=new BASE_IMAGE::();
		$return->SetBody($this->GetBody());
		return $return;
	}

	sub Set{
		my($this,$source)=@_;

		$this->SetBody($source->GetBody());
		return;
	}

	sub Add{
		my($this,$source)=@_;

		$this->AddBody($source->GetBody());
		return;
	}

	sub GetSub{
		my($this,$size,$offset)=@_;
		my($return);

		$return=new BASE_IMAGE::();
		$return->SetBody($this->GetSubBody($size,$offset));
		return $return;
	}

	sub SetSub{
		my($this,$source,$size,$offset)=@_;

		$this->SetSubBody($source->GetBody(),$size,$offset);
		return;
	}

	sub GetBYTE{
		my($this,$offset)=@_;
		my($return);

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset+1){
			return undef;
		}
		$^H|=8;
		$return=unpack('C',substr($$this{'Body'},$offset,1));
		$$this{'Current'}=$offset+1;
		$^H&=~8;
		return $return;
	}

	sub SetBYTE{
		my($this,$value,$offset)=@_;

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset){
			$this->SetSize($offset);
		}
		$^H|=8;
		$$this{'Current'}=$offset+1;
		$$this{'Body'}=substr($$this{'Body'},0,$offset).pack('C',$value).substr($$this{'Body'},$$this{'Current'});
		$^H&=~8;
		return;
	}

	sub AddBYTE{
		my($this,$value)=@_;

		$^H|=8;
		$$this{'Body'}.=pack('C',$value);
		$^H&=~8;
		$$this{'Current'}=$this->GetSize();
		return;
	}

	sub GetWORD_L{
		my($this,$offset)=@_;
		my($return);

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset+2){
			return undef;
		}
		$^H|=8;
		$return=unpack('v',substr($$this{'Body'},$offset,2));
		$$this{'Current'}=$offset+2;
		$^H&=~8;
		return $return;
	}

	sub SetWORD_L{
		my($this,$value,$offset)=@_;

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset){
			$this->SetSize($offset);
		}
		$^H|=8;
		$$this{'Current'}=$offset+2;
		$$this{'Body'}=substr($$this{'Body'},0,$offset).pack('v',$value).substr($$this{'Body'},$$this{'Current'});
		$^H&=~8;
		return;
	}

	sub AddWORD_L{
		my($this,$value)=@_;

		$^H|=8;
		$$this{'Body'}.=pack('v',$value);
		$^H&=~8;
		$$this{'Current'}=$this->GetSize();
		return;
	}

	sub GetWORD_B{
		my($this,$offset)=@_;
		my($return);

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset+2){
			return undef;
		}
		$^H|=8;
		$return=unpack('n',substr($$this{'Body'},$offset,2));
		$$this{'Current'}=$offset+2;
		$^H&=~8;
		return $return;
	}

	sub SetWORD_B{
		my($this,$value,$offset)=@_;

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset){
			$this->SetSize($offset);
		}
		$^H|=8;
		$$this{'Current'}=$offset+2;
		$$this{'Body'}=substr($$this{'Body'},0,$offset).pack('n',$value).substr($$this{'Body'},$$this{'Current'});
		$^H&=~8;
		return;
	}

	sub AddWORD_B{
		my($this,$value)=@_;

		$^H|=8;
		$$this{'Body'}.=pack('n',$value);
		$^H&=~8;
		$$this{'Current'}=$this->GetSize();
		return;
	}

	sub GetDWORD_L{
		my($this,$offset)=@_;
		my($return);

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset+4){
			return undef;
		}
		$^H|=8;
		$return=unpack('V',substr($$this{'Body'},$offset,4));
		$$this{'Current'}=$offset+4;
		$^H&=~8;
		return $return;
	}

	sub SetDWORD_L{
		my($this,$value,$offset)=@_;

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset){
			$this->SetSize($offset);
		}
		$^H|=8;
		$$this{'Current'}=$offset+4;
		$$this{'Body'}=substr($$this{'Body'},0,$offset).pack('V',$value).substr($$this{'Body'},$$this{'Current'});
		$^H&=~8;
		return;
	}

	sub AddDWORD_L{
		my($this,$value)=@_;

		$^H|=8;
		$$this{'Body'}.=pack('V',$value);
		$^H&=~8;
		$$this{'Current'}=$this->GetSize();
		return;
	}

	sub GetDWORD_B{
		my($this,$offset)=@_;
		my($return);

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset+4){
			return undef;
		}
		$^H|=8;
		$return=unpack('N',substr($$this{'Body'},$offset,4));
		$$this{'Current'}=$offset+4;
		$^H&=~8;
		return $return;
	}

	sub SetDWORD_B{
		my($this,$value,$offset)=@_;

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset){
			$this->SetSize($offset);
		}
		$^H|=8;
		$$this{'Current'}=$offset+4;
		$$this{'Body'}=substr($$this{'Body'},0,$offset).pack('N',$value).substr($$this{'Body'},$$this{'Current'});
		$^H&=~8;
		return;
	}

	sub AddDWORD_B{
		my($this,$value)=@_;

		$^H|=8;
		$$this{'Body'}.=pack('N',$value);
		$^H&=~8;
		$$this{'Current'}=$this->GetSize();
		return;
	}

	sub GetSBYTE{
		my($this,$offset)=@_;
		my($return);

		$return=$this->GetBYTE($offset);
		if(0x80<=$return){
			$return-=0x100;
		}
		return $return;
	}

	sub SetSBYTE{
		my($this,$value,$offset)=@_;

		if($value<0){
			$value+=0x100;
		}
		$this->SetBYTE($value,$offset);
		return;
	}

	sub AddSBYTE{
		my($this,$value)=@_;

		if($value<0){
			$value+=0x100;
		}
		$this->AddBYTE($value);
		return;
	}

	sub GetSWORD_L{
		my($this,$offset)=@_;
		my($return);

		$return=$this->GetWORD_L($offset);
		if(0x8000<=$return){
			$return-=0x10000;
		}
		return $return;
	}

	sub SetSWORD_L{
		my($this,$value,$offset)=@_;

		if($value<0){
			$value+=0x10000;
		}
		$this->SetWORD_L($value,$offset);
		return;
	}

	sub AddSWORD_L{
		my($this,$value)=@_;

		if($value<0){
			$value+=0x10000;
		}
		$this->AddWORD_L($value);
		return;
	}

	sub GetSWORD_B{
		my($this,$offset)=@_;
		my($return);

		$return=$this->GetWORD_B($offset);
		if(0x8000<=$return){
			$return-=0x10000;
		}
		return $return;
	}

	sub SetSWORD_B{
		my($this,$value,$offset)=@_;

		if($value<0){
			$value+=0x10000;
		}
		$this->SetWORD_B($value,$offset);
		return;
	}

	sub AddSWORD_B{
		my($this,$value)=@_;

		if($value<0){
			$value+=0x10000;
		}
		$this->AddWORD_B($value);
		return;
	}

	sub GetSDWORD_L{
		my($this,$offset)=@_;
		my($return);

		$return=$this->GetDWORD_L($offset);
		if(2147483648<=$return){
			$return-=4294967296;
		}
		return $return;
	}

	sub SetSDWORD_L{
		my($this,$value,$offset)=@_;

		if($value<0){
			$value+=4294967296;
		}
		$this->SetDWORD_L($value,$offset);
		return;
	}

	sub AddSDWORD_L{
		my($this,$value)=@_;

		if($value<0){
			$value+=4294967296;
		}
		$this->AddDWORD_L($value);
		return;
	}

	sub GetSDWORD_B{
		my($this,$offset)=@_;
		my($return);

		$return=$this->GetDWORD_B($offset);
		if(2147483648<=$return){
			$return-=4294967296;
		}
		return $return;
	}

	sub SetSDWORD_B{
		my($this,$value,$offset)=@_;

		if($value<0){
			$value+=4294967296;
		}
		$this->SetDWORD_B($value,$offset);
		return;
	}

	sub AddSDWORD_B{
		my($this,$value)=@_;

		if($value<0){
			$value+=4294967296;
		}
		$this->AddDWORD_B($value);
		return;
	}

	sub GetFLOAT_L{
		my($this,$offset)=@_;
		my($return);

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset+4){
			return undef;
		}
		$^H|=8;
		$return=unpack('f',pack('L',unpack('V',substr($$this{'Body'},$offset,4))));
		$$this{'Current'}=$offset+4;
		$^H&=~8;
		return $return;
	}

	sub SetFLOAT_L{
		my($this,$value,$offset)=@_;

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset){
			$this->SetSize($offset);
		}
		$^H|=8;
		$$this{'Current'}=$offset+4;
		$$this{'Body'}=substr($$this{'Body'},0,$offset).pack('V',unpack('L',pack('f',$value))).substr($$this{'Body'},$$this{'Current'});
		$^H&=~8;
		return;
	}

	sub AddFLOAT_L{
		my($this,$value)=@_;

		$^H|=8;
		$$this{'Body'}.=pack('V',unpack('L',pack('f',$value)));
		$^H&=~8;
		$$this{'Current'}=$this->GetSize();
		return;
	}

	sub GetFLOAT_B{
		my($this,$offset)=@_;
		my($return);

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset+4){
			return undef;
		}
		$^H|=8;
		$return=unpack('f',pack('L',unpack('N',substr($$this{'Body'},$offset,4))));
		$$this{'Current'}=$offset+4;
		$^H&=~8;
		return $return;
	}

	sub SetFLOAT_B{
		my($this,$value,$offset)=@_;

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset){
			$this->SetSize($offset);
		}
		$^H|=8;
		$$this{'Current'}=$offset+4;
		$$this{'Body'}=substr($$this{'Body'},0,$offset).pack('N',unpack('L',pack('f',$value))).substr($$this{'Body'},$$this{'Current'});
		$^H&=~8;
		return;
	}

	sub AddFLOAT_B{
		my($this,$value)=@_;

		$^H|=8;
		$$this{'Body'}.=pack('N',unpack('L',pack('f',$value)));
		$^H&=~8;
		$$this{'Current'}=$this->GetSize();
		return;
	}

	sub GetSTRING{
		my($this,$offset)=@_;
		my($return);

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset+1){
			return undef;
		}
		$^H|=8;
		($return)=split(/\0/,substr($$this{'Body'},$offset));
		$$this{'Current'}=$offset+length($return);
		if(substr($$this{'Body'},$$this{'Current'},1) eq "\0"){
			$$this{'Current'}++;
		}
		$^H&=~8;
		return $return;
	}

	sub SetSTRING{
		my($this,$value,$offset)=@_;

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset){
			$this->SetSize($offset);
		}
		$^H|=8;
		$value.="\0";
		$$this{'Current'}=$offset+length($value);
		$$this{'Body'}=substr($$this{'Body'},0,$offset).$value.substr($$this{'Body'},$$this{'Current'});
		$^H&=~8;
		return;
	}

	sub AddSTRING{
		my($this,$value)=@_;

		$^H|=8;
		$value.="\0";
		$$this{'Body'}.=$value;
		$^H&=~8;
		$$this{'Current'}=$this->GetSize();
		return;
	}

	sub SetFREE{
		my($this,$value,$offset)=@_;

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset){
			$this->SetSize($offset);
		}
		$^H|=8;
		$$this{'Current'}=$offset+length($value);
		$$this{'Body'}=substr($$this{'Body'},0,$offset).$value.substr($$this{'Body'},$$this{'Current'});
		$^H&=~8;
		return;
	}

	sub AddFREE{
		my($this,$value)=@_;

		$^H|=8;
		$$this{'Body'}.=$value;
		$^H&=~8;
		$$this{'Current'}=$this->GetSize();
		return;
	}

	sub GetLINE{
		my($this,$offset)=@_;
		my($return);

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset+1){
			return undef;
		}
		$^H|=8;
		($return)=split(/\r\n|[\n\r]/,substr($$this{'Body'},$offset));
		$$this{'Current'}=$offset+length($return);
		if(substr($$this{'Body'},$$this{'Current'},2) eq "\r\n"){
			$$this{'Current'}+=2;
		}elsif(substr($$this{'Body'},$$this{'Current'},1)=~/[\n\r]/){
			$$this{'Current'}++;
		}
		$^H&=~8;
		return $return;
	}

	sub SetLINE{
		my($this,$value,$offset)=@_;

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset){
			$this->SetSize($offset);
		}
		$^H|=8;
		$value.=$BASE::ReturnChar;
		$$this{'Current'}=$offset+length($value);
		$$this{'Body'}=substr($$this{'Body'},0,$offset).$value.substr($$this{'Body'},$$this{'Current'});
		$^H&=~8;
		return;
	}

	sub AddLINE{
		my($this,$value)=@_;

		$^H|=8;
		$value.=$BASE::ReturnChar;
		$$this{'Body'}.=$value;
		$^H&=~8;
		$$this{'Current'}=$this->GetSize();
		return;
	}

	sub UndoLINE{
		my($this,$offset)=@_;
		my(@temp);

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset+1){
			return undef;
		}
		$^H|=8;
		if(substr($$this{'Body'},$offset-2,2) eq "\r\n"){
			$offset-=2;
		}elsif(substr($$this{'Body'},$offset-1,1)=~/[\n\r]/){
			$offset--;
		}
		@temp=split(/\r\n|[\n\r]/,substr($$this{'Body'},0,$offset));
		$$this{'Current'}=$offset-length($temp[$#temp]);
		$^H&=~8;
		return;
	}

	sub SetTEXT{
		my($this,$value,$offset)=@_;

		if(not defined $offset){
			$offset=$$this{'Current'};
		}
		if($this->GetSize()<$offset){
			$this->SetSize($offset);
		}
		$^H|=8;
		$value=~s/\r\n|[\n\r]/$BASE::ReturnChar/g;
		$$this{'Current'}=$offset+length($value);
		$$this{'Body'}=substr($$this{'Body'},0,$offset).$value.substr($$this{'Body'},$$this{'Current'});
		$^H&=~8;
		return;
	}

	sub AddTEXT{
		my($this,$value)=@_;

		$^H|=8;
		$value=~s/\r\n|[\n\r]/$BASE::ReturnChar/g;
		$$this{'Body'}.=$value;
		$^H&=~8;
		$$this{'Current'}=$this->GetSize();
		return;
	}

	sub SetVARIABLE{
		my($this,$value,$offset)=@_;

		if(defined $offset){
			$this->SetCurrent($offset);
		}
		$this->SetVARIABLE_body($value,0,undef,{},0);
		return;
	}

	sub SetVARIABLE_body{
		my($this,$value,$indent,$parent,$shown,$recursive)=@_;

		if(
			($BASE_IMAGE::VARIABLERecursiveLimit<=0)||
			($recursive<=$BASE_IMAGE::VARIABLERecursiveLimit)
		){
			my($type,$i,$key);

			$type=ref($value);
			if(
				($type ne '')&&
				($type ne 'REF')&&
				($type ne 'SCALAR')&&
				($type ne 'ARRAY')&&
				($type ne 'HASH')&&
				($type ne 'CODE')&&
				($type ne 'GLOB')
			){
				$this->SetSubBody("${type}::");
				(undef,$type)=split(/[\=\(]/,$value);
			}
			if($type eq ''){
				if($value=~/[\r\n]/){
					($_)=split(/[\r\n]/,$value,2);
					$_.='...';
				}else{
					$_=$value;
				}
				$this->SetSubBody("$_");
				if(not defined $parent){
					$this->SetLINE();
				}
			}elsif($type eq 'SCALAR'){
				if($$value=~/[\r\n]/){
					($_)=split(/[\r\n]/,$$value,2);
					$_.='...';
				}else{
					$_=$$value;
				}
				$this->SetSubBody("$_");
				if(not defined $parent){
					$this->SetLINE();
				}
			}elsif($type eq 'REF'){
				$this->SetSubBody('->');
				if(defined $$shown{$value}){
					$this->SetSubBody('...');
				}else{
					$$shown{$value}='x';
					$this->SetVARIABLE_body($$value,$indent,'REF',$shown,$recursive+1);
				}
			}elsif($type eq 'ARRAY'){
				for($i=0;$i<@$value;$i++){
					if(ref($$value[$i])){
						last;
					}
				}
				$this->SetSubBody('[');
				if(
					(defined $$shown{$value})||(
						(0<$BASE_IMAGE::VARIABLERecursiveLimit)&&
						($BASE_IMAGE::VARIABLERecursiveLimit<$recursive+1)
					)
				){
					$this->SetSubBody('...');
				}else{
					$$shown{$value}='x';
					if(($i==@$value)&&($parent ne 'ARRAY')){
						for($i=0;$i<@$value;$i++){
							$this->SetVARIABLE_body($$value[$i],$indent,'ARRAY',$shown,$recursive+1);
							if($i<@$value-1){
								$this->SetSubBody(',');
							}
						}
					}else{
						if(0<@$value){
							$this->SetLINE();
							$this->SetSubBody(' 'x($indent*4+4));
							for($i=0;$i<@$value;$i++){
								$type=ref($$value[$i]);
								if($type){
									$this->SetVARIABLE_body($$value[$i],$indent+1,'ARRAY',$shown,$recursive+1);
								}else{
									$this->SetVARIABLE_body($$value[$i],$indent,'ARRAY',$shown,$recursive+1);
								}
								if($i<@$value-1){
									$this->SetSubBody(',');
								}else{
									$this->SetLINE();
									$this->SetSubBody(' 'x($indent*4));
								}
							}
						}
					}
				}
				$this->SetSubBody(']');
				if(not defined $parent){
					$this->SetLINE();
				}
			}elsif($type eq 'HASH'){
				$this->SetSubBody('{');
				if(
					(defined $$shown{$value})||(
						(0<$BASE_IMAGE::VARIABLERecursiveLimit)&&
						($BASE_IMAGE::VARIABLERecursiveLimit<$recursive+1)
					)
				){
					$this->SetSubBody('...');
				}else{
					my($keys);

					$$shown{$value}='x';
					$keys=0;
					foreach $key(sort keys %$value){
						if($key=~/[\r\n]/){
							($_)=split(/[\r\n]/,$key,2);
							$_.='...';
						}else{
							$_=$key;
						}
						$this->SetLINE();
						$this->SetSubBody(' 'x($indent*4+4)."$_=>");
						if(ref($$value{$key})){
							$this->SetVARIABLE_body($$value{$key},$indent+1,'HASH',$shown,$recursive+1);
						}else{
							$this->SetVARIABLE_body($$value{$key},$indent,'HASH',$shown,$recursive+1);
						}
						$keys++;
					}
					if($keys){
						$this->SetLINE();
						$this->SetSubBody(' 'x($indent*4));
					}
				}
				$this->SetSubBody('}');
				if(not defined $parent){
					$this->SetLINE();
				}
			}else{
				$this->SetSubBody("<$type>");
				if(not defined $parent){
					$this->SetLINE();
				}
			}
		}else{
			$this->SetSubBody('...');
			if(not defined $parent){
				$this->SetLINE();
			}
		}
		return;
	}

	sub Save{
		my($this,$filename)=@_;
		my($hfile);

		if($filename eq ''){
			print $$this{'Body'};
		}else{
			open($hfile,">$filename");
			binmode($hfile);
			syswrite($hfile,$$this{'Body'},$this->GetSize(),0);
			close($hfile);
		}
		$$this{'Current'}=$this->GetSize();
		return;
	}

	sub Flush{
		my($this,$filename)=@_;
		my($hfile);

		if($filename eq ''){
			print $$this{'Body'};
			$this->SetBody('');
		}else{
			open($hfile,">$filename");
			binmode($hfile);
			syswrite($hfile,$$this{'Body'},$this->GetSize(),0);
			close($hfile);
		}
		$$this{'Current'}=$this->GetSize();
		return;
	}

	sub Load{
		my($this,$filename)=@_;
		my($hfile);

		if($filename eq ''){
			$$this{'Body'}='';
			while(<STDIN>){
				$$this{'Body'}.=$_;
			}
		}else{
			open($hfile,"<$filename");
			binmode($hfile);
			sysread($hfile,$$this{'Body'},(stat($hfile))[7],0);
			close($hfile);
		}
		$$this{'Current'}=$this->GetSize();
		return;
	}

	sub ArrangeFileName{
		my($filename)=@_;

		$filename=~s/\\/\//g;
		if(substr($filename,1,1) eq ':'){
			$filename='/'.STRING_Lower(substr($filename,0,1)).'/'.substr($filename,2);
		}
		return $filename;
	}
}

1;
