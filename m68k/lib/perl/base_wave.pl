##############################################################################
##																			##
##																			##
##									OFW										##
##																			##
##	'base_wave.pl'									2024 written by int71	##
##############################################################################

use strict;
require 'base_riff.pl';

#
#	WAVE
#

{
	package WAVE;

	BEGIN{
		our($Version,$Date)=('2.00','2021/03/27');

		return;
	}

	sub new{
		my($class,$filename)=@_;
		my($this);

		$this={};
		bless($this,$class);
		$this->Clear();
		if(defined $filename){
			$this->Load($filename);
		}
		return $this;
	}

	sub Clear{
		my($this)=@_;

		$$this{'Channel'}=[[],[]];
		$$this{'SamplesPerSec'}=44100;
		$$this{'Bits'}=16;
		return;
	}

	sub GetChannels{
		my($this)=@_;

		return @{$$this{'Channel'}};
	}

	sub GetSamples{
		my($this)=@_;

		return @{$$this{'Channel'}[0]};
	}

	sub Save{
		my($this,$filename)=@_;
		my($riff,$image,$channels,$length,$i);

		$channels=@{$$this{'Channel'}};
		$riff=new BASE_RIFF::();
		$riff->SetType('RIFF','WAVE');
		$image=$riff->GetSub('fmt ')->GetBody();
		$image->SetWORD_L(1);
		$image->SetWORD_L($channels);
		$image->SetDWORD_L($$this{'SamplesPerSec'});
		$image->SetDWORD_L($channels*$$this{'SamplesPerSec'}*$$this{'Bits'}/8);
		$image->SetWORD_L($channels*$$this{'Bits'}/8);
		$image->SetWORD_L($$this{'Bits'});
		$image=$riff->GetSub('data')->GetBody();
		$image->SetCurrent(0);
		$length=@{$$this{'Channel'}[0]};
		for($i=1;$i<$channels;$i++){
			if($length<@{$$this{'Channel'}[$i]}){
				$length=@{$$this{'Channel'}[$i]};
			}
		}
		if($$this{'Bits'}==8){
			for($i=0;$i<$length;$i++){
				my($j);

				for($j=0;$j<$channels;$j++){
					$image->SetSBYTE($$this{'Channel'}[$j][$i]);
				}
			}
		}elsif($$this{'Bits'}==16){
			for($i=0;$i<$length;$i++){
				my($j);

				for($j=0;$j<$channels;$j++){
					$image->SetSWORD_L($$this{'Channel'}[$j][$i]);
				}
			}
		}
		$riff->Save("$filename");
		return;
	}

	sub Load{
		my($this,$filename)=@_;
		my($riff,$image,$channels,$length,$i);

		$this->Clear();
		$riff=new BASE_RIFF::($filename);
		$image=$riff->GetSub('fmt ')->GetBody();
		$channels=$image->GetWORD_L(2);
		$$this{'SamplesPerSec'}=$image->GetDWORD_L(4);
		$$this{'Bits'}=$image->GetWORD_L(14);
		$$this{'Channel'}=[];
		$image=$riff->GetSub('data')->GetBody();
		$image->SetCurrent(0);
		$length=$image->GetSize();
		if($$this{'Bits'}==8){
			$length=int($length/$channels);
			for($i=0;$i<$length;$i++){
				my($j);

				for($j=0;$j<$channels;$j++){
					$$this{'Channel'}[$j][$i]=$image->GetSBYTE();
				}
			}
		}elsif($$this{'Bits'}==16){
			$length=int($length/$channels/2);
			for($i=0;$i<$length;$i++){
				my($j);

				for($j=0;$j<$channels;$j++){
					$$this{'Channel'}[$j][$i]=$image->GetSWORD_L();
				}
			}
		}
		return;
	}
}

1;
