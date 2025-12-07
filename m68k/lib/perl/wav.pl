##############################################################################
##																			##
##																			##
##									OFW										##
##																			##
##	'wav.pl'										2024 written by int71	##
##############################################################################

use strict;
require 'base_riff.pl';

#
#	WAV
#

{
	package WAV;

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

		%$this=(
			'Info'=>{
				'Artist'=>'',
				'Title'=>'',
				'Album'=>'',
				'Genre'=>'',
				'Track'=>''
			},
			'Channels'=>2,
			'Frequency'=>44100,
			'Resolution'=>2,
			'Image'=>new BASE_IMAGE::()
		);
		return;
	}

	sub SetInfo{
		my($this,$artist,$title,$album,$genre,$track)=@_;

		$$this{'Info'}={
			'Artist'=>$artist,
			'Title'=>$title,
			'Album'=>$album,
			'Genre'=>$genre,
			'Track'=>$track
		};
		return;
	}

	sub SetFormat{
		my($this,$channels,$frequency,$resolution)=@_;

		$$this{'Channels'}=$channels;
		$$this{'Frequency'}=$frequency;
		$$this{'Resolution'}=$resolution;
		return;
	}

	sub GetSamples{
		my($this)=@_;

		return $$this{'Image'}->GetSize()/($$this{'Channels'}*$$this{'Resolution'});
	}

	sub GetSubImage{
		my($this,$size,$offset)=@_;
		my($add);

		{
			my($samples,$end);

			$samples=$this->GetSamples();
			$end=$offset+$size;
			if($samples<$offset){
				$offset=$samples;
			}
			if($samples<$end){
				$end=$samples;
			}
			$samples=$end-$offset;
			$add=$size-$samples;
			$size=$samples;
		}
		if($$this{'Channels'}==1){
			if($$this{'Resolution'}==1){
				my($return,$i);

				$return=$$this{'Image'}->GetSub($size,$offset);
				for($i=0;$i<$add;$i++){
					$return->AddBYTE(0x80);
				}
				return $return
			}elsif($$this{'Resolution'}==2){
				my($return,$i);

				$return=$$this{'Image'}->GetSub($size*2,$offset*2);
				for($i=0;$i<$add;$i++){
					$return->AddWORD_L(0x0000);
				}
				return $return
			}
		}elsif($$this{'Channels'}==2){
			if($$this{'Resolution'}==1){
				my($return,$i);

				$return=$$this{'Image'}->GetSub($size*2,$offset*2);
				for($i=0;$i<$add;$i++){
					$return->AddWORD_L(0x8080);
				}
				return $return
			}elsif($$this{'Resolution'}==2){
				my($return,$i);

				$return=$$this{'Image'}->GetSub($size*4,$offset*4);
				for($i=0;$i<$add;$i++){
					$return->AddDWORD_L(0x00000000);
				}
				return $return
			}
		}
		return undef;
	}

	sub Save{
		my($this,$filename)=@_;
		my($riff,@riffbody);

		$riff=new BASE_RIFF::();
		$riff->SetType('RIFF','WAVE');
		{
			my(@chunkbody);

			#	'INFO'
			if($$this{'Info'}{'Artist'} ne ''){
				my($subchunk);

				#	'IART'
				$subchunk=new BASE_RIFF::();
				$subchunk->SetType('IART');
				$subchunk->GetBody()->SetSTRING($$this{'Info'}{'Artist'});
				$chunkbody[@chunkbody]=$subchunk;
			}
			if($$this{'Info'}{'Title'} ne ''){
				my($subchunk);

				#	'INAM'
				$subchunk=new BASE_RIFF::();
				$subchunk->SetType('INAM');
				$subchunk->GetBody()->SetSTRING($$this{'Info'}{'Title'});
				$chunkbody[@chunkbody]=$subchunk;
			}
			if($$this{'Info'}{'Album'} ne ''){
				my($subchunk);

				#	'IPRD'
				$subchunk=new BASE_RIFF::();
				$subchunk->SetType('IPRD');
				$subchunk->GetBody()->SetSTRING($$this{'Info'}{'Album'});
				$chunkbody[@chunkbody]=$subchunk;
			}
			if($$this{'Info'}{'Genre'} ne ''){
				my($subchunk);

				#	'IGNR'
				$subchunk=new BASE_RIFF::();
				$subchunk->SetType('IGNR');
				$subchunk->GetBody()->SetSTRING($$this{'Info'}{'Genre'});
				$chunkbody[@chunkbody]=$subchunk;
			}
			if($$this{'Info'}{'Track'} ne ''){
				my($subchunk);

				#	'ITRK'
				$subchunk=new BASE_RIFF::();
				$subchunk->SetType('ITRK');
				$subchunk->GetBody()->SetSTRING($$this{'Info'}{'Track'});
				$chunkbody[@chunkbody]=$subchunk;
			}
			if(0<scalar(@chunkbody)){
				my($chunk);

				$chunk=new BASE_RIFF::();
				$chunk->SetType('LIST','INFO');
				$chunk->SetSub(\@chunkbody);
				$riffbody[@riffbody]=$chunk;
			}
		}
		{
			my($chunk,$body);

			#	'fmt '
			$chunk=new BASE_RIFF::();
			$chunk->SetType('fmt ');
			$body=$chunk->GetBody();
			$body->SetWORD_L(0x0001);
			$body->SetWORD_L($$this{'Channels'});
			$body->SetDWORD_L($$this{'Frequency'});
			$body->SetDWORD_L($$this{'Channels'}*$$this{'Frequency'}*$$this{'Resolution'});
			$body->SetWORD_L($$this{'Channels'}*$$this{'Resolution'});
			$body->SetWORD_L($$this{'Resolution'}<<3);
			$body->SetWORD_L(0x0000);
			$riffbody[@riffbody]=$chunk;
		}
		{
			my($chunk,$body);

			#	'data'
			$chunk=new BASE_RIFF::();
			$chunk->SetType('data');
			$chunk->SetBody($$this{'Image'});
			$riffbody[@riffbody]=$chunk;
		}
		$riff->SetSub(\@riffbody);
		$riff->Save($filename);
		return;
	}

	sub Load{
		my($this,$filename)=@_;
		my($riff,$type,$id);

		$this->Clear();
		$riff=new BASE_RIFF::($filename);
		($type,$id)=$riff->GetType();
		if(
			($type eq 'RIFF')&&
			($id eq 'WAVE')
		){
			my($sub);

			foreach $sub($riff->GetSub()){
				my($body);

				($type,$id)=$sub->GetType();
				$body=$sub->GetBody();
				if($type eq 'fmt '){
					if($body->GetWORD_L(0)==0x0001){
						$$this{'Channels'}=$body->GetWORD_L(0x02);
						$$this{'Frequency'}=$body->GetDWORD_L(0x04);
						$$this{'Resolution'}=$body->GetWORD_L(0x0e)>>3;
					}else{
						$this->Clear();
						return;
					}
				}elsif($type eq 'data'){
					$$this{'Image'}=$body;
				}elsif($type eq 'LIST'){
					if($id eq 'INFO'){
						my($infobody);

						foreach $infobody($sub->GetSub()){
							my($string);

							($type,$id)=$infobody->GetType();
							$string=$infobody->GetBody()->GetSTRING(0);
							if($type eq 'IART'){
								$$this{'Info'}{'Artist'}=$string;
							}elsif($type eq 'INAM'){
								$$this{'Info'}{'Title'}=$string;
							}elsif($type eq 'IPRD'){
								$$this{'Info'}{'Album'}=$string;
							}elsif($type eq 'IGNR'){
								$$this{'Info'}{'Genre'}=$string;
							}elsif($type eq 'ITRK'){
								$$this{'Info'}{'Track'}=$string+0;
							}
						}
					}
				}
			}
		}
		return;
	}
}

1;
