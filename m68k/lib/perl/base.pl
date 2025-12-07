##############################################################################
##																			##
##																			##
##									OFW										##
##																			##
##	'base.pl'										2025 written by int71	##
##############################################################################

use strict;
use utf8;
use Time::HiRes;
use Cwd qw/getcwd/;
use Unicode::Japanese;
require 'base_image.pl';
require 'base_math.pl';

{
	package BASE;

	BEGIN{
		our($Version,$Date)=('2.44','2025/11/14');
		our($Year,$Month,$Day,$Hour,$Minute,$Second,$ProcessID,$ReturnChar,$Self,$PathBase,$EndianNative,$STDOUT);

		$INC[@INC]='./';
		srand($$^time());
		$ProcessID=$$;
		$ReturnChar="\r\n";
		return;
	}

	END{
		$BASE::STDOUT->Save('');
		return;
	}

	sub new{
		my($class)=@_;
		my($original,@temp);

		($BASE::Year,$BASE::Month,$BASE::Day,$BASE::Hour,$BASE::Minute,$BASE::Second)=GetCurrentTime();
		$original=BASE::GetCurrentDirectory();
		@temp=split(/[\\\/]/,$0);$BASE::Self=$temp[$#temp];$#temp--;chdir(join('/',@temp));
		$BASE::PathBase=BASE::GetCurrentDirectory();
		if(pack('L',0x40414243) eq 'CBA@'){
			$BASE::EndianNative='L';
		}else{
			$BASE::EndianNative='B';
		}
		chdir($original);
		BASE::new_Inherit();
		$BASE::STDOUT=new BASE_IMAGE::();
		new BASE_MATH::();
		if($::{'main::'} eq '*main::main::'){
			my($args,$i,@argument,%option,$return);

			$args=@ARGV;
			for($i=0;$i<$args;$i++){
				if(substr($ARGV[$i],0,1) eq '-'){
					my($optionname);

					$optionname=substr($ARGV[$i],1);
					if($i+1<$args){
						if(substr($ARGV[$i+1],0,1) ne '-'){
							$option{$optionname}=BASE::new_ArgumentEscape($ARGV[$i+1]);
							$i++;
						}else{
							$option{$optionname}='';
						}
					}else{
						$option{$optionname}='';
					}
				}else{
					$argument[@argument]=BASE::new_ArgumentEscape($ARGV[$i]);
				}
			}
			$return=eval('&main::main(\@argument,\%option);');
			if($@){
				warn($@);
			}else{
				exit($return);
			}
		}
		return;
	}

	sub new_ArgumentEscape{
		my($argument)=@_;

		$argument=BASE::STRING_Replace($argument,'\\-','-');
		$argument=BASE::STRING_Replace($argument,'\\\\','\\');
		return $argument;
	}

	sub new_Inherit{
		my(%supers,%temp);

		foreach(keys %::){
			if(/^(\w+)\:\:$/){
				if(eval("0<scalar(\@${1}::_super)?1:0;")){
					foreach(@{eval("\\\@${1}::_super")}){
						$supers{$1}.="$_\t";
					}
				}
			}
		}
		%temp=%supers;
		foreach(keys %temp){
			if(defined $supers{$_}){
				BASE::new_Inherit_Body($_);
			}
		}
		return;

		sub new_Inherit_Body{
			my($self)=@_;
			my($super);

			foreach $super(split(/\t/,$supers{$self})){
				my($symbol);
				if(defined $supers{$super}){
					BASE::new_Inherit_Body($super);
				}
				foreach $symbol(keys %{eval("\\\%${super}::")}){
					#	継承はsubだけ、ourは継承しない
					if(
						(eval("defined \&${super}::${symbol}?1:0;"))&&
						(!eval("defined \&${self}::${symbol}?1:0;"))
					){
						eval("\*${self}::${symbol}=\\\&${super}::${symbol};");
					}
				}
			}
			delete $supers{$self};
			return;
		}
	}

	sub SetCurrentDirectory{
		my($directory)=@_;

		chdir($directory);
		return;
	}

	sub GetCurrentDirectory{
		return Cwd::getcwd();
	}

	sub ListFile{
		my($directory)=@_;
		my(@entry,$hdirectory,$name);

		if(substr($directory,-1) eq '/'){
			$directory=substr($directory,0,length($directory)-1);
		}
		undef @entry;
		opendir($hdirectory,$directory);
		while($name=readdir($hdirectory)){
			if(!-d "$directory/$name"){
				$entry[@entry]=$name;
			}
		}
		closedir($hdirectory);
		return @entry;
	}

	sub ListDirectory{
		my($directory,$condition)=@_;
		my(@entry,$hdirectory,$name);

		if(substr($directory,-1) eq '/'){
			$directory=substr($directory,0,length($directory)-1);
		}
		undef @entry;
		opendir($hdirectory,$directory);
		while($name=readdir($hdirectory)){
			if(-d "$directory/$name"){
				if(($name ne '.')&&($name ne '..')){
					$entry[@entry]=$name;
				}
			}
		}
		closedir($hdirectory);
		return @entry;
	}

	sub ListAllFile{
		my($directory)=@_;
		my(@entry);

		foreach(&ListFile($directory)){
			$entry[@entry]="$directory/$_";
		}
		foreach(&ListDirectory($directory)){
			@entry=(@entry,&ListAllFile("$directory/$_"));
		}
		return @entry;
	}

	sub MoveFile{
		my($current,$new)=@_;

		rename($current,$new);
		return;
	}

	sub DeleteFile{
		my($filename)=@_;

		unlink($filename);
		return;
	}

	sub TouchFile{
		my($filename)=@_;
		my($now)=time;

		utime($now,$now,$filename);
		return;
	}

	sub GetFileSize{
		my($filename)=@_;

		if(-e $filename){
			return (-s $filename);
		}else{
			return undef;
		}
	}

	sub GetFileTimeStamp{
		my($filename)=@_;

		if(-e $filename){
			return (stat $filename)[9];
		}else{
			return undef;
		}
	}

	sub GetCurrentTime{
		my($year,$month,$day,$hour,$minute,$second);

		($second,$minute,$hour,$day,$month,$year)=localtime(time());
		$year+=1900;
		$month=substr('0'.($month+1),-2);
		$day=substr('0'.$day,-2);
		$hour=substr('0'.$hour,-2);
		$minute=substr('0'.$minute,-2);
		$second=substr('0'.$second,-2);
		return ($year,$month,$day,$hour,$minute,$second);
	}

	sub GetExecutionTime{
		my($sub)=@_;
		my($time);

		$time=Time::HiRes::gettimeofday();
		&$sub;
		return int((Time::HiRes::gettimeofday()-$time)*1000)/1000;
	}

	sub GetInteraction{
		my($prompt)=@_;

		print "$prompt ";
		$_=<STDIN>;s/[\r\n]//g;
		return $_;
	}

	sub Print{
		my(@source)=@_;
		my($current);

		foreach $current(@source){
			if(ref($current) eq ''){
				$current=~s/\r\n|\r|\n/$BASE::ReturnChar/g;
				$BASE::STDOUT->SetSubBody($current);
			}else{
				$BASE::STDOUT->SetVARIABLE($current);
			}
		}
		$BASE::STDOUT->Flush();
		return;
	}

	sub Pause{
		my(@source)=@_;

		Print(@source);
		$_=<STDIN>;
		return;
	}

	sub Sign{
		my($source)=@_;

		return ($source==0)?0:(
			(0<$source)?1:-1
		);
	}

	sub Absolute{
		my($source)=@_;

		return (0<=$source)?$source:-$source;
	}

	sub Round{
		my($source)=@_;

		return (0<=$source)?int($source+.5):int($source-.5);
	}

	sub Floor{
		my($source)=@_;

		return int($source);
	}

	sub Ceil{
		my($source)=@_;

		if($source==int($source)){
			return $source;
		}else{
			return (0<=$source)?int($source)+1:int($source)-1;
		}
	}

	sub Maximum{
		my($destination,$source)=@_;

		return ($destination<$source)?$source:$destination;
	}

	sub Minimum{
		my($destination,$source)=@_;

		return ($destination<$source)?$destination:$source;
	}

	sub Fit{
		my($destination,$minimum,$maximum)=@_;

		return ($destination<$minimum)?$minimum:(
			($maximum<$destination)?$maximum:$destination
		);
	}

	sub STRING_FromSJIS{
		my($source)=@_;

		return Unicode::Japanese->new($source,'sjis')->get();
	}

	sub STRING_SJIS{
		my($source)=@_;

		return Unicode::Japanese->new($source)->sjis();
	}

	sub STRING_Full{
		my($source)=@_;

		return Unicode::Japanese->new($source)->h2z()->get();
	}

	sub STRING_Half{
		my($source)=@_;

		return Unicode::Japanese->new($source)->z2h()->get();
	}

	sub STRING_Upper{
		my($source)=@_;

		$source=~tr/[a-z]/[A-Z]/;
		return $source;
	}

	sub STRING_Lower{
		my($source)=@_;

		$source=~tr/[A-Z]/[a-z]/;
		return $source;
	}

	sub STRING_Hex2Num{
		my($source)=@_;

		return vec(pack('H8',substr('0000000'.$source,-8)),0,32);
	}

	sub STRING_Num2Hex{
		my($source)=@_;

		return sprintf('%08X',$source);
	}

	sub STRING_String2Array{
		my($source)=@_;
		my($image,$size,$i,@return);

		$image=new BASE_IMAGE::();
		$image->SetBody($source);
		$size=$image->GetSize();
		for($i=0;$i<$size;$i++){
			my($code);

			$code=$image->GetBYTE($i);
			if(
				((0x81<=$code)&&($code<=0x9f))||
				((0xe0<=$code)&&($code<=0xfc))
			){
				$i++;
				if($i<$size){
					$return[@return]=($code<<8)+$image->GetBYTE($i);
				}
			}else{
				$return[@return]=$code;
			}
		}
		return @return;
	}

	sub STRING_Array2String{
		my($source)=@_;
		my($image,$size,$i);

		$image=new BASE_IMAGE::();
		$size=@$source;
		for($i=0;$i<$size;$i++){
			if($$source[$i]<0x100){
				$image->SetBYTE($$source[$i]);
			}else{
				$image->SetWORD_B($$source[$i]);
			}
		}
		return $image->GetBody();
	}

	sub STRING_Replace{
		my($source,$from,$to)=@_;
		my($length,$index);

		$length=length($from);
		$index=0;
		while(0<=($index=index($source,$from,$index))){
			$source=substr($source,0,$index).$to.substr($source,$index+$length);
			$index+=$length;
		}
		return $source;
	}

	sub STRING_GetPath{
		my($source)=@_;

		$source=~s/\\/\//g;
		{
			my($index)=rindex($source,'/');

			if($index==-1){
				return '';
			}else{
				return substr($source,0,$index);
			}
		}
	}

	sub STRING_GetFile{
		my($source)=@_;

		$source=~s/\\/\//g;
		{
			my($index)=rindex($source,'/');

			if($index==-1){
				return $source;
			}else{
				return substr($source,$index+1);
			}
		}
	}

	sub STRING_GetExtension{
		my($source)=@_;
		my(@part);

		{
			my($index)=rindex($source,'.');

			if($index==-1){
				return '';
			}else{
				return substr($source,$index+1);
			}
		}
	}

	sub STRING_RemoveExtension{
		my($source)=@_;
		my(@part);

		{
			my($index)=rindex($source,'.');

			if($index==-1){
				return $source;
			}else{
				return substr($source,0,$index);
			}
		}
	}

	sub STRING_RemoveRelative{
		my($source)=@_;

		if(substr($source,0,1) ne '/'){
			$source=GetCurrentDirectory()."/$source";
		}
		{
			my(@part)=split(/\//,$source);
			my($npart)=scalar(@part);
			my($ipart);

			for($ipart=0;$ipart<$npart;++$ipart){
				if($part[$ipart] eq '.'){
					splice(@part,$ipart,1);
					--$ipart;
					--$npart;
				}elsif($part[$ipart] eq '..'){
					if(0<$ipart){
						splice(@part,$ipart-1,2);
						$ipart-=2;
						$npart-=2;
					}
				}
			}
			return join('/',@part);
		}
	}
}

1;
