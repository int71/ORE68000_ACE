##############################################################################
##																			##
##																			##
##									OFW										##
##																			##
##	'base_math.pl'									2026 written by int71	##
##############################################################################

use strict;

#
#	BASE_MATH
#

{
	package BASE_MATH;

	BEGIN{
		our($Version,$Date)=('2.10','2026/03/27');
		our($Angle1,$Angle2,$Angle4,$Angle8,$Pi,$AngleMultiply,$AngleMultiplyInverse,$Root22);

		return;
	}

	sub new{
		my($class,$angleround)=@_;

		if($angleround==0){
			$angleround=360;
		}
		$BASE_MATH::Angle1=$angleround;
		$BASE_MATH::Angle2=$angleround*.5;
		$BASE_MATH::Angle4=$angleround*.25;
		$BASE_MATH::Angle8=$angleround*.125;
		$BASE_MATH::Pi=atan2(1,0)*2;
		$BASE_MATH::AngleMultiply=$BASE_MATH::Pi/$BASE_MATH::Angle2;
		$BASE_MATH::AngleMultiplyInverse=$BASE_MATH::Angle2/$BASE_MATH::Pi;
		$BASE_MATH::Root22=sqrt(2)*.5;
		return;
	}

	sub Sin{
		my($angle)=@_;

		while($angle<0){
			$angle+=$BASE_MATH::Angle1;
		}
		while($angle>=$BASE_MATH::Angle1){
			$angle-=$BASE_MATH::Angle1;
		}
		if($angle<$BASE_MATH::Angle8){
			return sin($angle*$BASE_MATH::AngleMultiply);
		}
		if($angle==$BASE_MATH::Angle8){
			return $BASE_MATH::Root22;
		}
		if($angle<$BASE_MATH::Angle4){
			return BASE_MATH::Cos($BASE_MATH::Angle4-$angle);
		}
		if($angle<$BASE_MATH::Angle2){
			return BASE_MATH::Cos($angle-$BASE_MATH::Angle4);
		}
		return -BASE_MATH::Sin($angle-$BASE_MATH::Angle2);
	}

	sub Cos{
		my($angle)=@_;

		while($angle<0){
			$angle+=$BASE_MATH::Angle1;
		}
		while($angle>=$BASE_MATH::Angle1){
			$angle-=$BASE_MATH::Angle1;
		}
		if($angle<$BASE_MATH::Angle8){
			return cos($angle*$BASE_MATH::AngleMultiply);
		}
		if($angle==$BASE_MATH::Angle8){
			return $BASE_MATH::Root22;
		}
		if($angle<$BASE_MATH::Angle4){
			return BASE_MATH::Sin($BASE_MATH::Angle4-$angle);
		}
		if($angle<$BASE_MATH::Angle2){
			return -BASE_MATH::Sin($angle-$BASE_MATH::Angle4);
		}
		if($angle==$BASE_MATH::Angle2){
			return -1;
		}
		return BASE_MATH::Cos($BASE_MATH::Angle1-$angle);
	}

	sub Atan{
		my($x,$y)=@_;

		if($y<0){
			return -BASE_MATH::Atan($x,-$y);
		}
		if($x<0){
			return $BASE_MATH::Angle2-BASE_MATH::Atan(-$x,$y);
		}
		if($x<$y){
			return $BASE_MATH::Angle4-atan2($x,$y)*$BASE_MATH::AngleMultiplyInverse;
		}elsif($x==$y){
			return $BASE_MATH::Angle8;
		}else{
			return atan2($y,$x)*$BASE_MATH::AngleMultiplyInverse;
		}
	}

	sub Hermite{
		my($ratio)=@_;
		my($ratio2,$ratio3,$h0,$h1,$h2,$h3);

		$ratio2=$ratio*$ratio;
		$ratio3=$ratio*$ratio2;
		$h1=3.0*$ratio2-$ratio3-$ratio3;
		$h0=1.0-$h1;
		$h3=$ratio3-$ratio2;
		$h2=$h3-$ratio2+$ratio;
		return ($h0,$h1,$h2,$h3);
	}

	sub Bezier{
		my($x0,$x1,$x2,$x3,$ratio)=@_;
		my($a,$b,$c,$ratio2,$ratio3);

		$ratio2=$ratio*$ratio;
		$ratio3=$ratio2*$ratio;
		$c=3.0*($x1-$x0);
		$b=3.0*($x2-$x1)-$c;
		$a=$x3-$x0-$c-$b;
		return $a*$ratio3+$b*$ratio2+$c*$ratio+$x0;
	}
}

#
#	BASE_VECTOR1
#

{
	package BASE_VECTOR1;

	BEGIN{
		return;
	}

	sub new{
		my($class,$value0)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->Set($value0);
		return $this;
	}

	sub Duplicate{
		my($this)=@_;

		return new BASE_VECTOR1::($this->Get());
	}

	sub Get{
		my($this)=@_;

		return ($$this[0]);
	}

	sub Set{
		my($this,$value0)=@_;

		(
			$$this[0]
		)=(
			$value0+.0
		);
		return;
	}

	sub Copy{
		my($this,$source)=@_;

		(
			$$this[0]
		)=(
			$$source[0]
		);
		return $this;
	}

	sub Regularize{
		my($this)=@_;

		return new BASE_VECTOR1::(split(/\t/,join("\t",$this->Get())));
	}

	sub IsEqual{
		my($this,$source)=@_;

		return (
			($$this[0]==$$source[0])
		);
	}

	sub Negate{
		my($this)=@_;

		return new BASE_VECTOR1::(-$$this[0]);
	}

	sub Normalize{
		my($this)=@_;

		return new BASE_VECTOR1::(1);
	}

	sub Maximum{
		my($this,$source)=@_;

		return new BASE_VECTOR1::(
			($$this[0]<$$source[0])?$$source[0]:$$this[0]
		);
	}

	sub Minimum{
		my($this,$source)=@_;

		return new BASE_VECTOR1::(
			($$this[0]<$$source[0])?$$this[0]:$$source[0]
		);
	}

	sub Add{
		my($this,$source)=@_;

		return new BASE_VECTOR1::(
			$$this[0]+$$source[0]
		);
	}

	sub Subtract{
		my($this,$source)=@_;

		return new BASE_VECTOR1::(
			$$this[0]-$$source[0]
		);
	}

	sub Multiply{
		my($this,$source)=@_;
		my($class);

		$class=ref($source);
		if($class eq 'BASE_MATRIX11'){
			return new BASE_VECTOR1::(
				$$this[0]*$$source[0]
			);
		}elsif($class eq 'BASE_MATRIX22'){
			return new BASE_VECTOR1::(
				$$this[0]*$$source[0]+$$source[4]
			);
		}else{
			return new BASE_VECTOR1::(
				$$this[0]*$source
			);
		}
	}

	sub Divide{
		my($this,$source)=@_;

		$source=1/$source;
		return new BASE_VECTOR1::(
			$$this[0]*$source
		);
	}

	sub Dot{
		my($this,$source)=@_;

		return $$this[0]*$$source[0];
	}

	sub Normal{
		my($this)=@_;

		return abs($$this[0]);
	}

	sub Normal2{
		my($this)=@_;

		return $$this[0]*$$this[0];
	}
}

#
#	BASE_VECTOR2
#

{
	package BASE_VECTOR2;

	BEGIN{
	}

	sub new{
		my($class,$value0,$value1)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->Set($value0,$value1);
		return $this;
	}

	sub Duplicate{
		my($this)=@_;

		return new BASE_VECTOR2::($this->Get());
	}

	sub Get{
		my($this)=@_;

		return ($$this[0],$$this[1]);
	}

	sub Set{
		my($this,$value0,$value1)=@_;

		(
			$$this[0],$$this[1]
		)=(
			$value0+.0,$value1+.0
		);
		return;
	}

	sub Copy{
		my($this,$source)=@_;

		(
			$$this[0],$$this[1]
		)=(
			$$source[0],$$source[1]
		);
		return $this;
	}

	sub Regularize{
		my($this)=@_;

		return new BASE_VECTOR2::(split(/\t/,join("\t",$this->Get())));
	}

	sub IsEqual{
		my($this,$source)=@_;

		return (
			($$this[0]==$$source[0])&&
			($$this[1]==$$source[1])
		);
	}

	sub Negate{
		my($this)=@_;

		return new BASE_VECTOR2::(-$$this[0],-$$this[1]);
	}

	sub Normalize{
		my($this)=@_;
		my($normal);

		$normal=$this->Normal();
		if(0<$normal){
			return $this->Divide($this->Normal());
		}else{
			return new BASE_VECTOR2::(1,0);
		}
	}

	sub Maximum{
		my($this,$source)=@_;

		return new BASE_VECTOR2::(
			($$this[0]<$$source[0])?$$source[0]:$$this[0],
			($$this[1]<$$source[1])?$$source[1]:$$this[1]
		);
	}

	sub Minimum{
		my($this,$source)=@_;

		return new BASE_VECTOR2::(
			($$this[0]<$$source[0])?$$this[0]:$$source[0],
			($$this[1]<$$source[1])?$$this[1]:$$source[1]
		);
	}

	sub Add{
		my($this,$source)=@_;

		return new BASE_VECTOR2::(
			$$this[0]+$$source[0],
			$$this[1]+$$source[1]
		);
	}

	sub Subtract{
		my($this,$source)=@_;

		return new BASE_VECTOR2::(
			$$this[0]-$$source[0],
			$$this[1]-$$source[1]
		);
	}

	sub Multiply{
		my($this,$source)=@_;
		my($class);

		$class=ref($source);
		if($class eq 'BASE_MATRIX22'){
			return new BASE_VECTOR2::(
				$$this[0]*$$source[0]+$$this[1]*$$source[4],
				$$this[0]*$$source[1]+$$this[1]*$$source[5]
			);
		}elsif($class eq 'BASE_MATRIX33'){
			return new BASE_VECTOR2::(
				$$this[0]*$$source[0]+$$this[1]*$$source[4]+$$source[8],
				$$this[0]*$$source[1]+$$this[1]*$$source[5]+$$source[9]
			);
		}else{
			return new BASE_VECTOR2::(
				$$this[0]*$source,
				$$this[1]*$source
			);
		}
	}

	sub Divide{
		my($this,$source)=@_;

		$source=1/$source;
		return new BASE_VECTOR2::(
			$$this[0]*$source,
			$$this[1]*$source
		);
	}

	sub Dot{
		my($this,$source)=@_;

		return $$this[0]*$$source[0]+$$this[1]*$$source[1];
	}

	sub Normal{
		my($this)=@_;

		return sqrt($this->Dot($this));
	}

	sub Normal2{
		my($this)=@_;

		return $this->Dot($this);
	}
}

#
#	BASE_VECTOR3
#

{
	package BASE_VECTOR3;

	BEGIN{
	}

	sub new{
		my($class,$value0,$value1,$value2)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->Set($value0,$value1,$value2);
		return $this;
	}

	sub Duplicate{
		my($this)=@_;

		return new BASE_VECTOR3::($this->Get());
	}

	sub Get{
		my($this)=@_;

		return ($$this[0],$$this[1],$$this[2]);
	}

	sub Set{
		my($this,$value0,$value1,$value2)=@_;

		(
			$$this[0],$$this[1],$$this[2]
		)=(
			$value0+.0,$value1+.0,$value2+.0
		);
		return;
	}

	sub Copy{
		my($this,$source)=@_;

		(
			$$this[0],$$this[1],$$this[2]
		)=(
			$$source[0],$$source[1],$$source[2]
		);
		return $this;
	}

	sub Regularize{
		my($this)=@_;

		return new BASE_VECTOR3::(split(/\t/,join("\t",$this->Get())));
	}

	sub IsEqual{
		my($this,$source)=@_;

		return (
			($$this[0]==$$source[0])&&
			($$this[1]==$$source[1])&&
			($$this[2]==$$source[2])
		);
	}

	sub Negate{
		my($this)=@_;

		return new BASE_VECTOR3::(-$$this[0],-$$this[1],-$$this[2]);
	}

	sub Normalize{
		my($this)=@_;
		my($normal);

		$normal=$this->Normal();
		if(0<$normal){
			return $this->Divide($this->Normal());
		}else{
			return new BASE_VECTOR3::(1,0,0);
		}
	}

	sub Maximum{
		my($this,$source)=@_;

		return new BASE_VECTOR3::(
			($$this[0]<$$source[0])?$$source[0]:$$this[0],
			($$this[1]<$$source[1])?$$source[1]:$$this[1],
			($$this[2]<$$source[2])?$$source[2]:$$this[2]
		);
	}

	sub Minimum{
		my($this,$source)=@_;

		return new BASE_VECTOR3::(
			($$this[0]<$$source[0])?$$this[0]:$$source[0],
			($$this[1]<$$source[1])?$$this[1]:$$source[1],
			($$this[2]<$$source[2])?$$this[2]:$$source[2]
		);
	}

	sub Add{
		my($this,$source)=@_;

		return new BASE_VECTOR3::(
			$$this[0]+$$source[0],
			$$this[1]+$$source[1],
			$$this[2]+$$source[2]
		);
	}

	sub Subtract{
		my($this,$source)=@_;

		return new BASE_VECTOR3::(
			$$this[0]-$$source[0],
			$$this[1]-$$source[1],
			$$this[2]-$$source[2]
		);
	}

	sub Cross{
		my($this,$source)=@_;

		return new BASE_VECTOR3::(
			$$this[1]*$$source[2]-$$this[2]*$$source[1],
			$$this[2]*$$source[0]-$$this[0]*$$source[2],
			$$this[0]*$$source[1]-$$this[1]*$$source[0]
		);
	}

	sub Multiply{
		my($this,$source)=@_;
		my($class);

		$class=ref($source);
		if($class eq 'BASE_MATRIX33'){
			return new BASE_VECTOR3::(
				$$this[0]*$$source[0]+$$this[1]*$$source[4]+$$this[2]*$$source[8],
				$$this[0]*$$source[1]+$$this[1]*$$source[5]+$$this[2]*$$source[9],
				$$this[0]*$$source[2]+$$this[1]*$$source[6]+$$this[2]*$$source[10]
			);
		}elsif($class eq 'BASE_MATRIX44'){
			return new BASE_VECTOR3::(
				$$this[0]*$$source[0]+$$this[1]*$$source[4]+$$this[2]*$$source[8]+$$source[12],
				$$this[0]*$$source[1]+$$this[1]*$$source[5]+$$this[2]*$$source[9]+$$source[13],
				$$this[0]*$$source[2]+$$this[1]*$$source[6]+$$this[2]*$$source[10]+$$source[14]
			);
		}else{
			return new BASE_VECTOR3::(
				$$this[0]*$source,
				$$this[1]*$source,
				$$this[2]*$source
			);
		}
	}

	sub Divide{
		my($this,$source)=@_;

		$source=1/$source;
		return new BASE_VECTOR3::(
			$$this[0]*$source,
			$$this[1]*$source,
			$$this[2]*$source
		);
	}

	sub Dot{
		my($this,$source)=@_;

		return $$this[0]*$$source[0]+$$this[1]*$$source[1]+$$this[2]*$$source[2];
	}

	sub Normal{
		my($this)=@_;

		return sqrt($this->Dot($this));
	}

	sub Normal2{
		my($this)=@_;

		return $this->Dot($this);
	}
}

#
#	BASE_VECTOR4
#

{
	package BASE_VECTOR4;

	BEGIN{
	}

	sub new{
		my($class,$value0,$value1,$value2,$value3)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->Set($value0,$value1,$value2,$value3);
		return $this;
	}

	sub Duplicate{
		my($this)=@_;

		return new BASE_VECTOR4::($this->Get());
	}

	sub Get{
		my($this)=@_;

		return ($$this[0],$$this[1],$$this[2],$$this[3]);
	}

	sub Set{
		my($this,$value0,$value1,$value2,$value3)=@_;

		(
			$$this[0],$$this[1],$$this[2],$$this[3]
		)=(
			$value0+.0,$value1+.0,$value2+.0,$value3+.0
		);
		return;
	}

	sub Copy{
		my($this,$source)=@_;

		(
			$$this[0],$$this[1],$$this[2],$$this[3]
		)=(
			$$source[0],$$source[1],$$source[2],$$source[3]
		);
		return $this;
	}

	sub Regularize{
		my($this)=@_;

		return new BASE_VECTOR4::(split(/\t/,join("\t",$this->Get())));
	}

	sub IsEqual{
		my($this,$source)=@_;

		return (
			($$this[0]==$$source[0])&&
			($$this[1]==$$source[1])&&
			($$this[2]==$$source[2])&&
			($$this[3]==$$source[3])
		);
	}

	sub Negate{
		my($this)=@_;

		return new BASE_VECTOR4::(-$$this[0],-$$this[1],-$$this[2],-$$this[3]);
	}

	sub Normalize{
		my($this)=@_;
		my($normal);

		$normal=$this->Normal();
		if(0<$normal){
			return $this->Divide($this->Normal());
		}else{
			return new BASE_VECTOR4::(1,0,0,0);
		}
	}

	sub Maximum{
		my($this,$source)=@_;

		return new BASE_VECTOR4::(
			($$this[0]<$$source[0])?$$source[0]:$$this[0],
			($$this[1]<$$source[1])?$$source[1]:$$this[1],
			($$this[2]<$$source[2])?$$source[2]:$$this[2],
			($$this[3]<$$source[3])?$$source[3]:$$this[3]
		);
	}

	sub Minimum{
		my($this,$source)=@_;

		return new BASE_VECTOR4::(
			($$this[0]<$$source[0])?$$this[0]:$$source[0],
			($$this[1]<$$source[1])?$$this[1]:$$source[1],
			($$this[2]<$$source[2])?$$this[2]:$$source[2],
			($$this[3]<$$source[3])?$$this[3]:$$source[3]
		);
	}

	sub Add{
		my($this,$source)=@_;

		return new BASE_VECTOR4::(
			$$this[0]+$$source[0],
			$$this[1]+$$source[1],
			$$this[2]+$$source[2],
			$$this[3]+$$source[3]
		);
	}

	sub Subtract{
		my($this,$source)=@_;

		return new BASE_VECTOR4::(
			$$this[0]-$$source[0],
			$$this[1]-$$source[1],
			$$this[2]-$$source[2],
			$$this[3]-$$source[3]
		);
	}

	sub Multiply{
		my($this,$source)=@_;
		my($class);

		$class=ref($source);
		if($class eq 'BASE_MATRIX44'){
			return new BASE_VECTOR4::(
				$$this[0]*$$source[0]+$$this[1]*$$source[4]+$$this[2]*$$source[8]+$$this[3]*$$source[12],
				$$this[0]*$$source[1]+$$this[1]*$$source[5]+$$this[2]*$$source[9]+$$this[3]*$$source[13],
				$$this[0]*$$source[2]+$$this[1]*$$source[6]+$$this[2]*$$source[10]+$$this[3]*$$source[14],
				$$this[0]*$$source[3]+$$this[1]*$$source[7]+$$this[2]*$$source[11]+$$this[3]*$$source[15]
			);
		}else{
			return new BASE_VECTOR4::(
				$$this[0]*$source,
				$$this[1]*$source,
				$$this[2]*$source,
				$$this[3]*$source
			);
		}
	}

	sub Divide{
		my($this,$source)=@_;

		$source=1/$source;
		return new BASE_VECTOR4::(
			$$this[0]*$source,
			$$this[1]*$source,
			$$this[2]*$source,
			$$this[3]*$source
		);
	}

	sub Dot{
		my($this,$source)=@_;

		return $$this[0]*$$source[0]+$$this[1]*$$source[1]+$$this[2]*$$source[2]+$$this[3]*$$source[3];
	}

	sub Normal{
		my($this)=@_;

		return sqrt($this->Dot($this));
	}

	sub Normal2{
		my($this)=@_;

		return $this->Dot($this);
	}
}

#
#	BASE_MATRIX11
#

{
	package BASE_MATRIX11;

	BEGIN{
	}

	sub new{
		my($class,$value00)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->Set($value00);
		return $this;
	}

	sub newScaling1{
		my($class,$scaling)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->SetScaling1($scaling);
		return $this;
	}

	sub newReciprocalScaling1{
		my($class,$scaling)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->SetReciprocalScaling1($scaling);
		return $this;
	}

	sub Duplicate{
		my($this)=@_;

		return new BASE_MATRIX11::($this->Get());
	}

	sub Get{
		my($this)=@_;

		return (
			$$this[0]
		);
	}

	sub Set{
		my($this,$value00)=@_;

		(
			$$this[0]
		)=(
			$value00+.0
		);
		return;
	}

	sub SetScaling1{
		my($this,$scaling)=@_;
		my($x);

		($x)=$scaling->Get();
		(
			$$this[0]
		)=(
			$x
		);
		return;
	}

	sub SetReciprocalScaling1{
		my($this,$scaling)=@_;
		my($x);

		($x)=$scaling->Get();
		(
			$$this[0]
		)=(
			1.0/$x
		);
		return;
	}

	sub Copy{
		my($this,$source)=@_;

		(
			$$this[0]
		)=(
			$$source[0]
		);
		return $this;
	}

	sub Regularize{
		my($this)=@_;

		return new BASE_MATRIX11::(split(/\t/,join("\t",$this->Get())));
	}

	sub IsEqual{
		my($this,$source)=@_;

		return (
			($$this[0]==$$source[0])
		);
	}

	sub Add{
		my($this,$source)=@_;

		return new BASE_MATRIX11::(
			$$this[0]+$$source[0]
		);
	}

	sub Subtract{
		my($this,$source)=@_;

		return new BASE_MATRIX11::(
			$$this[0]-$$source[0]
		);
	}

	sub Multiply{
		my($this,$source)=@_;
		my($class);

		$class=ref($source);
		if($class eq 'BASE_MATRIX11'){
			return new BASE_MATRIX11::(
				$$this[0]*$$source[0]
			);
		}else{
			return new BASE_MATRIX11::(
				$$this[0]*$source
			);
		}
	}

	sub Divide{
		my($this,$source)=@_;

		$source=1/$source;
		return new BASE_MATRIX11::(
			$$this[0]*$source
		);
	}
}

#
#	BASE_MATRIX22
#

{
	package BASE_MATRIX22;

	BEGIN{
	}

	sub new{
		my($class,$value00,$value01,$value10,$value11)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->Set($value00,$value01,$value10,$value11);
		return $this;
	}

	sub newMoving1{
		my($class,$moving)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->SetMoving1($moving);
		return $this;
	}

	sub newReciprocalMoving1{
		my($class,$moving)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->SetReciprocalMoving1($moving);
		return $this;
	}

	sub newRotation2{
		my($class,$rotation)=@_;
		my($this);

		#	clockwise
		$this=[];
		bless($this,$class);
		$this->SetRotation2($rotation);
		return $this;
	}

	sub newReciprocalRotation2{
		my($class,$rotation)=@_;
		my($this);

		#	counterclockwise
		$this=[];
		bless($this,$class);
		$this->SetReciprocalRotation2($rotation);
		return $this;
	}

	sub newScaling2{
		my($class,$scaling)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->SetScaling2($scaling);
		return $this;
	}

	sub newReciprocalScaling2{
		my($class,$scaling)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->SetReciprocalScaling2($scaling);
		return $this;
	}

	sub Duplicate{
		my($this)=@_;

		return new BASE_MATRIX22::($this->Get());
	}

	sub Get{
		my($this)=@_;

		return (
			$$this[0],$$this[1],
			$$this[4],$$this[5]
		);
	}

	sub Set{
		my($this,$value00,$value01,$value10,$value11)=@_;

		(
			$$this[0],$$this[1],
			$$this[4],$$this[5]
		)=(
			$value00+.0,$value01+.0,
			$value10+.0,$value11+.0
		);
		return;
	}

	sub SetMoving1{
		my($this,$moving)=@_;
		my($x)=$moving->Get();

		$this->Set(
			1.0,	.0,
			$x,		1.0
		);
		return;
	}

	sub SetReciprocalMoving1{
		my($this,$moving)=@_;
		my($x)=$moving->Get();

		$this->Set(
			1.0,	.0,
			-$x,	1.0
		);
		return;
	}

	sub SetRotation2{
		my($this,$rotation)=@_;
		my($h)=$rotation->Get();
		my($sinh,$cosh)=(BASE_MATH::Sin($h),BASE_MATH::Cos($h));

		$this->Set(
			$cosh,	-$sinh,
			$sinh,	$cosh
		);
		return;
	}

	sub SetReciprocalRotation2{
		my($this,$rotation)=@_;
		my($h)=$rotation->Get();
		my($sinh,$cosh)=(BASE_MATH::Sin($h),BASE_MATH::Cos($h));

		$this->Set(
			$cosh,	$sinh,
			-$sinh,	$cosh
		);
		return;
	}

	sub SetScaling2{
		my($this,$scaling)=@_;
		my($x,$y)=$scaling->Get();

		$this->Set(
			$x,		.0,
			.0,		$y
		);
		return;
	}

	sub SetReciprocalScaling2{
		my($this,$scaling)=@_;
		my($x,$y)=$scaling->Get();

		$this->Set(
			1.0/$x,	.0,
			.0,		1.0/$y
		);
		return;
	}

	sub Copy{
		my($this,$source)=@_;

		(
			$$this[0],$$this[1],
			$$this[4],$$this[5]
		)=(
			$$source[0],$$source[1],
			$$source[4],$$source[5]
		);
		return $this;
	}

	sub Regularize{
		my($this)=@_;

		return new BASE_MATRIX22::(split(/\t/,join("\t",$this->Get())));
	}

	sub IsEqual{
		my($this,$source)=@_;

		return (
			($$this[0]==$$source[0])&&($$this[1]==$$source[1])&&
			($$this[4]==$$source[4])&&($$this[5]==$$source[5])
		);
	}

	sub Add{
		my($this,$source)=@_;

		return new BASE_MATRIX22::(
			$$this[0]+$$source[0],$$this[1]+$$source[1],
			$$this[4]+$$source[4],$$this[5]+$$source[5]
		);
	}

	sub Subtract{
		my($this,$source)=@_;

		return new BASE_MATRIX22::(
			$$this[0]-$$source[0],$$this[1]-$$source[1],
			$$this[4]-$$source[4],$$this[5]-$$source[5]
		);
	}

	sub Multiply{
		my($this,$source)=@_;
		my($class);

		$class=ref($source);
		if($class eq 'BASE_MATRIX22'){
			return new BASE_MATRIX22::(
				$$this[0]*$$source[0]+$$this[1]*$$source[4],$$this[0]*$$source[1]+$$this[1]*$$source[5],
				$$this[4]*$$source[0]+$$this[5]*$$source[4],$$this[4]*$$source[1]+$$this[5]*$$source[5]
			);
		}else{
			return new BASE_MATRIX22::(
				$$this[0]*$source,$$this[1]*$source,
				$$this[4]*$source,$$this[5]*$source
			);
		}
	}

	sub Divide{
		my($this,$source)=@_;

		$source=1/$source;
		return new BASE_MATRIX22::(
			$$this[0]*$source,$$this[1]*$source,
			$$this[4]*$source,$$this[5]*$source
		);
	}
}

#
#	BASE_MATRIX33
#

{
	package BASE_MATRIX33;

	BEGIN{
	}

	sub new{
		my($class,$value00,$value01,$value02,$value10,$value11,$value12,$value20,$value21,$value22)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->Set($value00,$value01,$value02,$value10,$value11,$value12,$value20,$value21,$value22);
		return $this;
	}

	sub newMoving2{
		my($class,$moving)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->SetMoving2($moving);
		return $this;
	}

	sub newReciprocalMoving2{
		my($class,$moving)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->SetReciprocalMoving2($moving);
		return $this;
	}

	sub newRotation3{
		my($class,$rotation)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->SetRotation3($rotation);
		return $this;
	}

	sub newReciprocalRotation3{
		my($class,$rotation)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->SetReciprocalRotation3($rotation);
		return $this;
	}

	sub newScaling3{
		my($class,$scaling)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->SetScaling3($scaling);
		return $this;
	}

	sub newReciprocalScaling3{
		my($class,$scaling)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->SetReciprocalScaling3($scaling);
		return $this;
	}

	sub Duplicate{
		my($this)=@_;

		return new BASE_MATRIX33::($this->Get());
	}

	sub Get{
		my($this)=@_;

		return (
			$$this[0],$$this[1],$$this[2],
			$$this[4],$$this[5],$$this[6],
			$$this[8],$$this[9],$$this[10]
		);
	}

	sub Set{
		my($this,$value00,$value01,$value02,$value10,$value11,$value12,$value20,$value21,$value22)=@_;

		(
			$$this[0],$$this[1],$$this[2],
			$$this[4],$$this[5],$$this[6],
			$$this[8],$$this[9],$$this[10]
		)=(
			$value00+.0,$value01+.0,$value02+.0,
			$value10+.0,$value11+.0,$value12+.0,
			$value20+.0,$value21+.0,$value22+.0
		);
		return;
	}

	sub SetMoving2{
		my($this,$moving)=@_;
		my($x,$y)=$moving->Get();

		$this->Set(
			1.0,	.0,		.0,
			.0,		1.0,	.0,
			$x,		$y,		1.0
		);
		return;
	}

	sub SetReciprocalMoving2{
		my($this,$moving)=@_;
		my($x,$y)=$moving->Get();

		$this->Set(
			1.0,	.0,		.0,
			.0,		1.0,	.0,
			-$x,	-$y,	1.0
		);
		return;
	}

	sub SetRotation3{
		my($this,$rotation)=@_;
		my($h,$p,$b)=$rotation->Get();
		my(
			$sinh,$cosh,
			$sinp,$cosp,
			$sinb,$cosb
		)=(
			BASE_MATH::Sin($h),BASE_MATH::Cos($h),
			BASE_MATH::Sin($p),BASE_MATH::Cos($p),
			BASE_MATH::Sin($b),BASE_MATH::Cos($b)
		);
		my(
			$coshcosb,$coshsinb,
			$sinhcosb,$sinhsinb
		)=(
			$cosh*$cosb,$cosh*$sinb,
			$sinh*$cosb,$sinh*$sinb
		);

		$this->Set(
			 $coshcosb+$sinhsinb*$sinp,	 $cosp*$sinb,	-$sinhcosb+$coshsinb*$sinp,
			-$coshsinb+$sinhcosb*$sinp,	 $cosp*$cosb,	 $sinhsinb+$coshcosb*$sinp,
			 $sinh*$cosp,				-$sinp,			 $cosh*$cosp
		);
		return;
	}

	sub SetReciprocalRotation3{
		my($this,$rotation)=@_;
		my($h,$p,$b)=$rotation->Get();
		my(
			$sinh,$cosh,
			$sinp,$cosp,
			$sinb,$cosb
		)=(
			BASE_MATH::Sin($h),BASE_MATH::Cos($h),
			BASE_MATH::Sin($p),BASE_MATH::Cos($p),
			BASE_MATH::Sin($b),BASE_MATH::Cos($b)
		);
		my(
			$coshcosb,$coshsinb,
			$sinhcosb,$sinhsinb
		)=(
			$cosh*$cosb,$cosh*$sinb,
			$sinh*$cosb,$sinh*$sinb
		);

		$this->Set(
			 $coshcosb+$sinhsinb*$sinp,	-$coshsinb+$sinhcosb*$sinp,	 $sinh*$cosp,
			 $cosp*$sinb,				 $cosp*$cosb,				-$sinp,
			-$sinhcosb+$coshsinb*$sinp,	 $sinhsinb+$coshcosb*$sinp,	 $cosh*$cosp
		);
		return;
	}

	sub SetScaling3{
		my($this,$scaling)=@_;
		my($x,$y,$z)=$scaling->Get();

		$this->Set(
			$x,		.0,		.0,
			.0,		$y,		.0,
			.0,		.0,		$z
		);
		return;
	}

	sub SetReciprocalScaling3{
		my($this,$scaling)=@_;
		my($x,$y,$z)=$scaling->Get();

		$this->Set(
			1.0/$x,	.0,		.0,
			.0,		1.0/$y,	.0,
			.0,		.0,		1.0/$z
		);
		return;
	}

	sub Copy{
		my($this,$source)=@_;

		(
			$$this[0],$$this[1],$$this[2],
			$$this[4],$$this[5],$$this[6],
			$$this[8],$$this[9],$$this[10]
		)=(
			$$source[0],$$source[1],$$source[2],
			$$source[4],$$source[5],$$source[6],
			$$source[8],$$source[9],$$source[10]
		);
		return $this;
	}

	sub Regularize{
		my($this)=@_;

		return new BASE_MATRIX33::(split(/\t/,join("\t",$this->Get())));
	}

	sub IsEqual{
		my($this,$source)=@_;

		return (
			($$this[0]==$$source[0])&&($$this[1]==$$source[1])&&($$this[2]==$$source[2])&&
			($$this[4]==$$source[4])&&($$this[5]==$$source[5])&&($$this[6]==$$source[6])&&
			($$this[8]==$$source[8])&&($$this[9]==$$source[9])&&($$this[10]==$$source[10])
		);
	}

	sub Add{
		my($this,$source)=@_;

		return new BASE_MATRIX33::(
			$$this[0]+$$source[0],$$this[1]+$$source[1],$$this[2]+$$source[2],
			$$this[4]+$$source[4],$$this[5]+$$source[5],$$this[6]+$$source[6],
			$$this[8]+$$source[8],$$this[9]+$$source[9],$$this[10]+$$source[10]
		);
	}

	sub Subtract{
		my($this,$source)=@_;

		return new BASE_MATRIX33::(
			$$this[0]-$$source[0],$$this[1]-$$source[1],$$this[2]-$$source[2],
			$$this[4]-$$source[4],$$this[5]-$$source[5],$$this[6]-$$source[6],
			$$this[8]-$$source[8],$$this[9]-$$source[9],$$this[10]-$$source[10]
		);
	}

	sub Multiply{
		my($this,$source)=@_;
		my($class);

		$class=ref($source);
		if($class eq 'BASE_MATRIX33'){
			return new BASE_MATRIX33::(
				$$this[0]*$$source[0]+$$this[1]*$$source[4]+$$this[2]*$$source[8],$$this[0]*$$source[1]+$$this[1]*$$source[5]+$$this[2]*$$source[9],$$this[0]*$$source[2]+$$this[1]*$$source[6]+$$this[2]*$$source[10],
				$$this[4]*$$source[0]+$$this[5]*$$source[4]+$$this[6]*$$source[8],$$this[4]*$$source[1]+$$this[5]*$$source[5]+$$this[6]*$$source[9],$$this[4]*$$source[2]+$$this[5]*$$source[6]+$$this[6]*$$source[10],
				$$this[8]*$$source[0]+$$this[9]*$$source[4]+$$this[10]*$$source[8],$$this[8]*$$source[1]+$$this[9]*$$source[5]+$$this[10]*$$source[9],$$this[8]*$$source[2]+$$this[9]*$$source[6]+$$this[10]*$$source[10]
			);
		}else{
			return new BASE_MATRIX33::(
				$$this[0]*$source,$$this[1]*$source,$$this[2]*$source,
				$$this[4]*$source,$$this[5]*$source,$$this[6]*$source,
				$$this[8]*$source,$$this[9]*$source,$$this[10]*$source
			);
		}
	}

	sub Divide{
		my($this,$source)=@_;

		$source=1/$source;
		return new BASE_MATRIX33::(
			$$this[0]*$source,$$this[1]*$source,$$this[2]*$source,
			$$this[4]*$source,$$this[5]*$source,$$this[6]*$source,
			$$this[8]*$source,$$this[9]*$source,$$this[10]*$source
		);
	}
}

#
#	BASE_MATRIX44
#

{
	package BASE_MATRIX44;

	BEGIN{
	}

	sub new{
		my($class,$value00,$value01,$value02,$value03,$value10,$value11,$value12,$value13,$value20,$value21,$value22,$value23,$value30,$value31,$value32,$value33)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->Set($value00,$value01,$value02,$value03,$value10,$value11,$value12,$value13,$value20,$value21,$value22,$value23,$value30,$value31,$value32,$value33);
		return $this;
	}

	sub newMoving3{
		my($class,$moving)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->SetMoving3($moving);
		return $this;
	}

	sub newReciprocalMoving3{
		my($class,$moving)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->SetReciprocalMoving3($moving);
		return $this;
	}

	sub newScaling4{
		my($class,$scaling)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->SetScaling4($scaling);
		return $this;
	}

	sub newReciprocalScaling4{
		my($class,$scaling)=@_;
		my($this);

		$this=[];
		bless($this,$class);
		$this->SetReciprocalScaling4($scaling);
		return $this;
	}

	sub Duplicate{
		my($this)=@_;

		return new BASE_MATRIX44::($this->Get());
	}

	sub Get{
		my($this)=@_;

		return (
			$$this[ 0],$$this[ 1],$$this[ 2],$$this[ 3],
			$$this[ 4],$$this[ 5],$$this[ 6],$$this[ 7],
			$$this[ 8],$$this[ 9],$$this[10],$$this[11],
			$$this[12],$$this[13],$$this[14],$$this[15]
		);
	}

	sub Set{
		my($this,$value00,$value01,$value02,$value03,$value10,$value11,$value12,$value13,$value20,$value21,$value22,$value23,$value30,$value31,$value32,$value33)=@_;

		(
			$$this[ 0],$$this[ 1],$$this[ 2],$$this[ 3],
			$$this[ 4],$$this[ 5],$$this[ 6],$$this[ 7],
			$$this[ 8],$$this[ 9],$$this[10],$$this[11],
			$$this[12],$$this[13],$$this[14],$$this[15]
		)=(
			$value00+.0,$value01+.0,$value02+.0,$value03+.0,
			$value10+.0,$value11+.0,$value12+.0,$value13+.0,
			$value20+.0,$value21+.0,$value22+.0,$value23+.0,
			$value30+.0,$value31+.0,$value32+.0,$value33+.0
		);
		return;
	}

	sub SetMoving3{
		my($this,$moving)=@_;
		my($x,$y,$z)=$moving->Get();

		$this->Set(
			1.0,	.0,		.0,		.0,
			.0,		1.0,	.0,		.0,
			.0,		.0,		1.0,	.0,
			$x,		$y,		$z,		1.0
		);
		return;
	}

	sub SetReciprocalMoving3{
		my($this,$moving)=@_;
		my($x,$y,$z)=$moving->Get();

		$this->Set(
			1.0,	.0,		.0,		.0,
			.0,		1.0,	.0,		.0,
			.0,		.0,		1.0,	.0,
			-$x,	-$y,	-$z,	1.0
		);
		return;
	}

	sub SetScaling4{
		my($this,$scaling)=@_;
		my($x,$y,$z,$w)=$scaling->Get();

		$this->Set(
			$x,		.0,		.0,		.0,
			.0,		$y,		.0,		.0,
			.0,		.0,		$z,		.0,
			.0,		.0,		.0,		$w
		);
		return;
	}

	sub SetReciprocalScaling4{
		my($this,$scaling)=@_;
		my($x,$y,$z,$w)=$scaling->Get();

		$this->Set(
			1.0/$x,	.0,		.0,		.0,
			.0,		1.0/$y,	.0,		.0,
			.0,		.0,		1.0/$z,	.0,
			.0,		.0,		.0,		1.0/$w
		);
		return;
	}

	sub Copy{
		my($this,$source)=@_;

		(
			$$this[ 0],$$this[ 1],$$this[ 2],$$this[ 3],
			$$this[ 4],$$this[ 5],$$this[ 6],$$this[ 7],
			$$this[ 8],$$this[ 9],$$this[10],$$this[11],
			$$this[12],$$this[13],$$this[14],$$this[15]
		)=(
			$$source[ 0],$$source[ 1],$$source[ 2],$$source[ 3],
			$$source[ 4],$$source[ 5],$$source[ 6],$$source[ 7],
			$$source[ 8],$$source[ 9],$$source[10],$$source[11],
			$$source[12],$$source[13],$$source[14],$$source[15]
		);
		return $this;
	}

	sub Regularize{
		my($this)=@_;

		return new BASE_MATRIX44::(split(/\t/,join("\t",$this->Get())));
	}

	sub IsEqual{
		my($this,$source)=@_;

		return (
			($$this[0]==$$source[0])&&($$this[1]==$$source[1])&&($$this[2]==$$source[2])&&($$this[3]==$$source[3])&&
			($$this[4]==$$source[4])&&($$this[5]==$$source[5])&&($$this[6]==$$source[6])&&($$this[7]==$$source[7])&&
			($$this[8]==$$source[8])&&($$this[9]==$$source[9])&&($$this[10]==$$source[10])&&($$this[11]==$$source[11])&&
			($$this[12]==$$source[12])&&($$this[13]==$$source[13])&&($$this[14]==$$source[14])&&($$this[15]==$$source[15])
		);
	}

	sub Add{
		my($this,$source)=@_;

		return new BASE_MATRIX44::(
			$$this[0]+$$source[0],$$this[1]+$$source[1],$$this[2]+$$source[2],$$this[3]+$$source[3],
			$$this[4]+$$source[4],$$this[5]+$$source[5],$$this[6]+$$source[6],$$this[7]+$$source[7],
			$$this[8]+$$source[8],$$this[9]+$$source[9],$$this[10]+$$source[10],$$this[11]+$$source[11],
			$$this[12]+$$source[12],$$this[13]+$$source[13],$$this[14]+$$source[14],$$this[15]+$$source[15]
		);
	}

	sub Subtract{
		my($this,$source)=@_;

		return new BASE_MATRIX44::(
			$$this[0]-$$source[0],$$this[1]-$$source[1],$$this[2]-$$source[2],$$this[3]-$$source[3],
			$$this[4]-$$source[4],$$this[5]-$$source[5],$$this[6]-$$source[6],$$this[7]-$$source[7],
			$$this[8]-$$source[8],$$this[9]-$$source[9],$$this[10]-$$source[10],$$this[11]-$$source[11],
			$$this[12]-$$source[12],$$this[13]-$$source[13],$$this[14]-$$source[14],$$this[15]-$$source[15]
		);
	}

	sub Multiply{
		my($this,$source)=@_;
		my($class);

		$class=ref($source);
		if($class eq 'BASE_MATRIX44'){
			return new BASE_MATRIX44::(
				$$this[0]*$$source[0]+$$this[1]*$$source[4]+$$this[2]*$$source[8]+$$this[3]*$$source[12],$$this[0]*$$source[1]+$$this[1]*$$source[5]+$$this[2]*$$source[9]+$$this[3]*$$source[13],$$this[0]*$$source[2]+$$this[1]*$$source[6]+$$this[2]*$$source[10]+$$this[3]*$$source[14],$$this[0]*$$source[3]+$$this[1]*$$source[7]+$$this[2]*$$source[11]+$$this[3]*$$source[15],
				$$this[4]*$$source[0]+$$this[5]*$$source[4]+$$this[6]*$$source[8]+$$this[7]*$$source[12],$$this[4]*$$source[1]+$$this[5]*$$source[5]+$$this[6]*$$source[9]+$$this[7]*$$source[13],$$this[4]*$$source[2]+$$this[5]*$$source[6]+$$this[6]*$$source[10]+$$this[7]*$$source[14],$$this[4]*$$source[3]+$$this[5]*$$source[7]+$$this[6]*$$source[11]+$$this[7]*$$source[15],
				$$this[8]*$$source[0]+$$this[9]*$$source[4]+$$this[10]*$$source[8]+$$this[11]*$$source[12],$$this[8]*$$source[1]+$$this[9]*$$source[5]+$$this[10]*$$source[9]+$$this[11]*$$source[13],$$this[8]*$$source[2]+$$this[9]*$$source[6]+$$this[10]*$$source[10]+$$this[11]*$$source[14],$$this[8]*$$source[3]+$$this[9]*$$source[7]+$$this[10]*$$source[11]+$$this[11]*$$source[15],
				$$this[12]*$$source[0]+$$this[13]*$$source[4]+$$this[14]*$$source[8]+$$this[15]*$$source[12],$$this[12]*$$source[1]+$$this[13]*$$source[5]+$$this[14]*$$source[9]+$$this[15]*$$source[13],$$this[12]*$$source[2]+$$this[13]*$$source[6]+$$this[14]*$$source[10]+$$this[15]*$$source[14],$$this[12]*$$source[3]+$$this[13]*$$source[7]+$$this[14]*$$source[11]+$$this[15]*$$source[15]
			);
		}else{
			return new BASE_MATRIX44::(
				$$this[0]*$source,$$this[1]*$source,$$this[2]*$source,$$this[3]*$source,
				$$this[4]*$source,$$this[5]*$source,$$this[6]*$source,$$this[7]*$source,
				$$this[8]*$source,$$this[9]*$source,$$this[10]*$source,$$this[11]*$source,
				$$this[12]*$source,$$this[13]*$source,$$this[14]*$source,$$this[15]*$source
			);
		}
	}

	sub Divide{
		my($this,$source)=@_;

		$source=1/$source;
		return new BASE_MATRIX44::(
			$$this[0]*$source,$$this[1]*$source,$$this[2]*$source,$$this[3]*$source,
			$$this[4]*$source,$$this[5]*$source,$$this[6]*$source,$$this[7]*$source,
			$$this[8]*$source,$$this[9]*$source,$$this[10]*$source,$$this[11]*$source,
			$$this[12]*$source,$$this[13]*$source,$$this[14]*$source,$$this[15]*$source
		);
	}
}

1;
