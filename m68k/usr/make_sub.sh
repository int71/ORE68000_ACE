#!/usr/local/ofw/bin/ofwmake
$MAKEBIN='../M68K_MAKEBIN.exe';
$MAKEFONT='../M68K_MAKEFONT.exe';
$User='sub';
$Source='../common/src';
$Include='../common/include';
$Object='sub.o';
$Release='../../image';
$C2OBJ="$MAKEBIN -m c2obj -I $Include";
$FONT2BIN="$MAKEFONT -s 16 -f \"KHドット小伝馬町16 幾何学的カナ\"";
$ROM_FONT="$Release/020.bin";
$OFW_OFW_CPP="$Source/ofw/ofw.cpp";
$OFW_OFW_OBJ="$Object/ofw_ofw.o";
$OFW_STD_STD_CPP="$Source/ofw/std/std.cpp";
$OFW_STD_STD_OBJ="$Object/ofw_std_std.o";
$ORE68000ACE_MEMORY_CPP="$Source/ore68000ace/memory.cpp";
$ORE68000ACE_MEMORY_OBJ="$Object/ore68000ace_memory.o";
$ORE68000ACE_DRIVER_VIDEO_CPP="$Source/ore68000ace/driver/video.cpp";
$ORE68000ACE_DRIVER_VIDEO_OBJ="$Object/ore68000ace_driver_video.o";
$ORE68000ACE_DRIVER_SOUND_CPP="$Source/ore68000ace/driver/sound.cpp";
$ORE68000ACE_DRIVER_SOUND_OBJ="$Object/ore68000ace_driver_sound.o";
$COMMON_BASE__CPP="common/base_.cpp";
$COMMON_BASE__OBJ="$Object/common_base_.o";
$COMMON_MAP_CPP="common/map.cpp";
$COMMON_MAP_OBJ="$Object/common_map.o";
$COMMON_SERIAL__CPP="common/serial_.cpp";
$COMMON_SERIAL__OBJ="$Object/common_serial_.o";
$COMMON_VECTOR2__CPP="common/vector2_.cpp";
$COMMON_VECTOR2__OBJ="$Object/common_vector2_.o";
$BASE_CPP="$User/base.cpp";
$BASE_OBJ="$Object/base.o";
$BOOT_CPP="$User/boot.cpp";
$BOOT_OBJ="$Object/boot.o";
$FAMILYBASIC_CPP="$User/familybasic.cpp";
$FAMILYBASIC_OBJ="$Object/familybasic.o";
$INTERRUPTER_CPP="$User/interrupter.cpp";
$INTERRUPTER_OBJ="$Object/interrupter.o";
$OS_CPP="$User/os.cpp";
$OS_OBJ="$Object/os.o";
$PATTERN_CPP="$User/pattern.cpp";
$PATTERN_OBJ="$Object/pattern.o";
$SERIAL_CPP="$User/serial.cpp";
$SERIAL_OBJ="$Object/serial.o";
$VECTOR2_CPP="$User/vector2.cpp";
$VECTOR2_OBJ="$Object/vector2.o";
$FONT='/c/Windows/Fonts//c/Windows/Fonts/KH-Dot-Kodenmachou-16-Ki.ttf';

{
	'.phony'=>['all','clean'],
	'.include_c'=>[$Include],
	'all'=>{
		depend=>[
			$OFW_OFW_OBJ,
			$OFW_STD_STD_OBJ,
			$ORE68000ACE_MEMORY_OBJ,
			$ORE68000ACE_DRIVER_VIDEO_OBJ,
			$ORE68000ACE_DRIVER_SOUND_OBJ,
			$COMMON_BASE__OBJ,
			$COMMON_MAP_OBJ,
			$COMMON_SERIAL__OBJ,
			$COMMON_VECTOR2__OBJ,
			$BASE_OBJ,
			$BOOT_OBJ,
			$FAMILYBASIC_OBJ,
			$INTERRUPTER_OBJ,
			$OS_OBJ,
			$PATTERN_OBJ,
			$SERIAL_OBJ,
			$VECTOR2_OBJ,
			$ROM_FONT
		]
	},
	'clean'=>{
		exec=>[
			"rm -f \"$Object/\"*.o \"$Object/\"*/*.o \"$Release/\"*.bin"
		]
	},
	$ROM_FONT=>{
		depend=>[$FONT],
		exec=>["$FONT2BIN -o \"$ROM_FONT\""]
	},
	$OFW_OFW_OBJ=>{
		depend_c=>[
			$OFW_OFW_CPP
		],
		exec=>["$C2OBJ \"$OFW_OFW_CPP\" -o \"$OFW_OFW_OBJ\""]
	},
	$OFW_STD_STD_OBJ=>{
		depend_c=>[
			$OFW_STD_STD_CPP
		],
		exec=>["$C2OBJ \"$OFW_STD_STD_CPP\" -o \"$OFW_STD_STD_OBJ\""]
	},
	$ORE68000ACE_MEMORY_OBJ=>{
		depend_c=>[
			$ORE68000ACE_MEMORY_CPP
		],
		exec=>["$C2OBJ \"$ORE68000ACE_MEMORY_CPP\" -o \"$ORE68000ACE_MEMORY_OBJ\""]
	},
	$ORE68000ACE_DRIVER_VIDEO_OBJ=>{
		depend_c=>[
			$ORE68000ACE_DRIVER_VIDEO_CPP
		],
		exec=>["$C2OBJ \"$ORE68000ACE_DRIVER_VIDEO_CPP\" -o \"$ORE68000ACE_DRIVER_VIDEO_OBJ\""]
	},
	$ORE68000ACE_DRIVER_SOUND_OBJ=>{
		depend_c=>[
			$ORE68000ACE_DRIVER_SOUND_CPP
		],
		exec=>["$C2OBJ \"$ORE68000ACE_DRIVER_SOUND_CPP\" -o \"$ORE68000ACE_DRIVER_SOUND_OBJ\""]
	},
	$COMMON_BASE__OBJ=>{
		depend_c=>[
			$COMMON_BASE__CPP
		],
		exec=>["$C2OBJ \"$COMMON_BASE__CPP\" -o \"$COMMON_BASE__OBJ\""]
	},
	$COMMON_MAP_OBJ=>{
		depend_c=>[
			$COMMON_MAP_CPP
		],
		exec=>["$C2OBJ \"$COMMON_MAP_CPP\" -o \"$COMMON_MAP_OBJ\""]
	},
	$COMMON_SERIAL__OBJ=>{
		depend_c=>[
			$COMMON_SERIAL__CPP
		],
		exec=>["$C2OBJ \"$COMMON_SERIAL__CPP\" -o \"$COMMON_SERIAL__OBJ\""]
	},
	$COMMON_VECTOR2__OBJ=>{
		depend_c=>[
			$COMMON_VECTOR2__CPP
		],
		exec=>["$C2OBJ \"$COMMON_VECTOR2__CPP\" -o \"$COMMON_VECTOR2__OBJ\""]
	},
	$BASE_OBJ=>{
		depend_c=>[
			$BASE_CPP
		],
		exec=>["$C2OBJ \"$BASE_CPP\" -o \"$BASE_OBJ\""]
	},
	$BOOT_OBJ=>{
		depend_c=>[
			$BOOT_CPP
		],
		exec=>["$C2OBJ \"$BOOT_CPP\" -o \"$BOOT_OBJ\""]
	},
	$FAMILYBASIC_OBJ=>{
		depend_c=>[
			$FAMILYBASIC_CPP
		],
		exec=>["$C2OBJ \"$FAMILYBASIC_CPP\" -o \"$FAMILYBASIC_OBJ\""]
	},
	$INTERRUPTER_OBJ=>{
		depend_c=>[
			$INTERRUPTER_CPP
		],
		exec=>["$C2OBJ \"$INTERRUPTER_CPP\" -o \"$INTERRUPTER_OBJ\""]
	},
	$OS_OBJ=>{
		depend_c=>[
			$OS_CPP
		],
		exec=>["$C2OBJ \"$OS_CPP\" -o \"$OS_OBJ\""]
	},
	$PATTERN_OBJ=>{
		depend_c=>[
			$PATTERN_CPP
		],
		exec=>["$C2OBJ \"$PATTERN_CPP\" -o \"$PATTERN_OBJ\""]
	},
	$SERIAL_OBJ=>{
		depend_c=>[
			$SERIAL_CPP
		],
		exec=>["$C2OBJ \"$SERIAL_CPP\" -o \"$SERIAL_OBJ\""]
	},
	$VECTOR2_OBJ=>{
		depend_c=>[
			$VECTOR2_CPP
		],
		exec=>["$C2OBJ \"$VECTOR2_CPP\" -o \"$VECTOR2_OBJ\""]
	}
};
