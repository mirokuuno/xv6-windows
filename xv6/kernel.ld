/* Kernel.ld for building on Windows
   Modified by Hiroshi Uno */

OUTPUT_ARCH(i386)
ENTRY(_start)

SECTIONS
{
	. = 0x80100000;

	.text : AT(0x100000) {
	entry.o(.text)
	PROVIDE(_binary_initcode_start = .);

		initcode_nb(.text)

	PROVIDE(_binary_initcode_end = .);

	PROVIDE(_binary_entryother_start = .);

		entryother_nb(.text)

	PROVIDE(_binary_entryother_end = .);

		*(.text .stub .text.* .gnu.linkonce.t.*)
	}
	PROVIDE(_binary_initcode_size = _binary_initcode_end - _binary_initcode_start);
	PROVIDE(_binary_entryother_size = _binary_entryother_end - _binary_entryother_start);

	PROVIDE(etext = .);

	.rodata : {
		*(.rdata .rdata* )
		*(.rodata .rodata.* .gnu.linkonce.r.*)
	}

	.stab : {
		PROVIDE(__STAB_BEGIN__ = .);
		*(.stab);
		PROVIDE(__STAB_END__ = .);
	}

	.stabstr : {
		PROVIDE(__STABSTR_BEGIN__ = .);
		*(.stabstr);
		PROVIDE(__STABSTR_END__ = .);
	}

	. = ALIGN(0x1000);

	PROVIDE(data = .);

	.data : {
		*(.data)
	}

	PROVIDE(edata = .);

	.bss : {
		*(.bss)
	}

	PROVIDE(end = .);

	/DISCARD/ : {
		*(.eh_frame .note.GNU-stack)
	}
}
