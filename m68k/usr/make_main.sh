#!/usr/local/ofw/bin/ofwmake
$MAKEBIN='../M68K_MAKEBIN.exe';
$User='main';
$Source='../common/src';
$Include='../common/include';
$Object='main.o';
$Release='../../image';
$C2OBJ="$MAKEBIN -m c2obj -I $Include";
$OBJ2BIN="$MAKEBIN -m obj2bin -padding 0";
$ROM_PROGRAM="$Release/000.bin";
$OFW_OFW_CPP="$Source/ofw/ofw.cpp";
$OFW_OFW_OBJ="$Object/ofw_ofw.o";
$OFW_STD_STD_CPP="$Source/ofw/std/std.cpp";
$OFW_STD_STD_OBJ="$Object/ofw_std_std.o";
$ORE68000ACE_MEMORY_CPP="$Source/ore68000ace/memory.cpp";
$ORE68000ACE_MEMORY_OBJ="$Object/ore68000ace_memory.o";
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
$INTERRUPTER_CPP="$User/interrupter.cpp";
$INTERRUPTER_OBJ="$Object/interrupter.o";
$OS_CPP="$User/os.cpp";
$OS_OBJ="$Object/os.o";
$SERIAL_CPP="$User/serial.cpp";
$SERIAL_OBJ="$Object/serial.o";
$VECTOR2_CPP="$User/vector2.cpp";
$VECTOR2_OBJ="$Object/vector2.o";

{
	'.phony'=>['all','clean'],
	'.include_c'=>[$Include],
	'all'=>{
		depend=>[
			$ROM_PROGRAM
		]
	},
	'clean'=>{
		exec=>[
			"rm -f \"$Object/\"*.o \"$Object/\"*/*.o \"$Release/\"*.bin"
		]
	},
	$ROM_PROGRAM=>{
		depend=>[
			$OFW_OFW_OBJ,
			$OFW_STD_STD_OBJ,
			$ORE68000ACE_MEMORY_OBJ,
			$COMMON_BASE__OBJ,
			$COMMON_MAP_OBJ,
			$COMMON_SERIAL__OBJ,
			$COMMON_VECTOR2__OBJ,
			$BASE_OBJ,
			$BOOT_OBJ,
			$INTERRUPTER_OBJ,
			$OS_OBJ,
			$SERIAL_OBJ,
			$VECTOR2_OBJ
		],
		exec=>["$OBJ2BIN \"$OFW_OFW_OBJ\" \"$OFW_STD_STD_OBJ\" \"$ORE68000ACE_MEMORY_OBJ\" \"$COMMON_BASE__OBJ\" \"$COMMON_MAP_OBJ\" \"$COMMON_SERIAL__OBJ\" \"$COMMON_VECTOR2__OBJ\" \"$BASE_OBJ\" \"$BOOT_OBJ\" \"$INTERRUPTER_OBJ\" \"$OS_OBJ\" \"$SERIAL_OBJ\" \"$VECTOR2_OBJ\" -o \"$ROM_PROGRAM\" -ca 000400 -cs 7efc00 -da 800000 -ds 200000"]
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
