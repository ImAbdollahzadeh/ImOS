#include "../include/LiBOSASM_CORE.h"
#include "../include/LiBOSASM_STRING.h"

int main(void)
{
	unsigned int lines = 0;
	unsigned int j;
	TRIPLE_PACKET* tp = 0;
	char p[128];
	
	const char* file = 
		"[LiBOSASM 32-bit]\n"
		"[ORIGIN 0x38EF501A]\n"
		"[SECTION .CODE]\n"
		"global _start\n"
		"global vid_pl\n"
		"_start:\n"
		"\tpush 0xAA001258\n"
		"\tpush ebp\n"
		"\t$1\n"
		"\tmov ebp, esp\n"
		"\tmov  WORD[memory_libos], cx\n"
		"\tmov dh,  BYTE[_THIRD_AND_LAST@@_LABEL:]\n"
		"\tmov ebp, DWORD[0xA0AB9856]\n"
		"\tmov dh,  BYTE[ebp]\n"
		"\tmov dx,  WORD[__SECOND_LABEL:]\n"
		"\tmov edi, 0xAABBCCDD\n"
		"\tmov bx, 0x45FF\n"
		"\tmov ch, 0x7E\n"
		"\tnop\n"
		"\tadd edx, 0xDDCCBB56\n"
		"\tadd BYTE[edi+0xAABBCCDD], al\n"
		"\tadd DWORD[eax+0xFD996614], 0xAABBCCDD\n"
		"\tsub eax, 0x43546576\n"
		"\tsub bp,  0xAABB\n"
		"\tsub bl,  0xA0\n"
		"\tsub DWORD[ecx], 0x43546576\n"
		"\tsub WORD[ebp+0x88202772], 0x4354\n"
		"\tsub BYTE[ebp], 0x44\n"
		"\tsub DWORD[esp], 0x43546576\n"
		"\tsub WORD[esp+0x88202772], 0x4354\n"
		"\tsub BYTE[esp], 0x44\n"
		"\tsub DWORD[_THIRD_AND_LAST@@_LABEL:], 0x11002399\n"
		"\tsub WORD[__SECOND_LABEL:], 0x1199\n"
		"\tnop\n"
		"\tsub ebp, DWORD[esp+0x12131415]\n"
		"\tsub bp, WORD[__SECOND_LABEL:]\n"
		"\tsub ah, BYTE[0x000000DF]\n"
		"\tsub DWORD[esp+0x12131415], esi\n"
		"\tsub WORD[__SECOND_LABEL:], sp\n"
		"\tsub BYTE[0x000055DF], al\n"
		"\tsub BYTE[esp+0x690055DF], dh\n"
		"\tnop\n"
		"\tsub cl, dh\n"
		"\tsub eax, edi\n"
		"\tsub bx, cx\n"
		"\txor di, 0x41FF\n"
		"\txor DWORD[esp+0x11223344], 0xfedcab12\n"
		"\txor WORD[ebp+0xFD551122], 0xFED2\n"
		"\txor BYTE[eax], 0x49\n"
		"\txor BYTE[__SECOND_LABEL:], 0xE5\n"
		"\tnop\n"
		"\tnop\n"
		"\tnop\n"
		"\txor eax, DWORD[__SECOND_LABEL:]\n"
		"\txor esp, DWORD[ebp+0x45879563]\n"
		"\txor si,  WORD[__SECOND_LABEL:]\n"
		"\txor cx,  WORD[ebx+0x66885511]\n"
		"\txor cx,  WORD[esp+0x000023F1]\n"
		"\txor bl,  BYTE[esp+0x998823F1]\n"
		"\txor ah,  BYTE[edx]\n"
		"\tnop\n"
		"\tnop\n"
		"\tnop\n"
		"\txor DWORD[__SECOND_LABEL:], esp\n"
		"\txor DWORD[ebp+0x45879563], ebx\n"
		"\txor WORD[__SECOND_LABEL:], cx\n"
		"\txor WORD[ebx+0x66885511], ax\n"
		"\txor WORD[esp+0x000023F1], bp\n"
		"\txor BYTE[esp+0x998823F1], bl\n"
		"\txor BYTE[edx], al\n"
		"\tmov BYTE[esp+0x28], 0x16\n"
		"\tnop\n"
		"\tnop\n"
		"\txor ebx, esp\n"
		"\txor eax, eax\n"
		"\txor esp, esp\n"
		"\txor ax, bx\n"
		"\txor dh, cl\n"
		"\txor bp, bp\n"
		"\txor bl, bl\n"
		"\tnop\n"
		"\tcmp eax, 0x45789641\n"
		"\tcmp ax, 0xCF12\n"
		"\tcmp bh, 0xCD\n"
		"\tnop\n"
		"\tcmp DWORD[esp+0x99977853], 0x45789641\n"
		"\tcmp WORD[ebp], 0xCF12\n"
		"\tcmp BYTE[_THIRD_AND_LAST@@_LABEL:], 0xCD\n"
		"\tnop\n"
		"\t$--numeric_token--\n"
		"\tcmp edi, DWORD[esp+0x99977853]\n"
		"\tcmp dx, WORD[ebp+0x00000021]\n"
		"\tcmp bh, BYTE[_THIRD_AND_LAST@@_LABEL:]\n"
		"\tnop\n"
		"\tcmp DWORD[ecx+0x99977853], esp\n"
		"\tcmp WORD[ebp+0x00000021], cx\n"
		"\tcmp BYTE[_THIRD_AND_LAST@@_LABEL:], ah\n"
		"\tnop\n"
		"\tcmp eax, esp\n"
		"\tcmp bp, cx\n"
		"\tcmp dl, ah\n"
		"\tmov WORD[ebp+0x00124585], esp\n"
		"\tjmp _THIRD_AND_LAST@@_LABEL:\n"
		"\tmov esp, ebp\n"
		"\t$_SECOND_LABEL_start\n"
		"__SECOND_LABEL:\n"
		"\tjmp __SECOND_LABEL:\n"
		"\tadd esp, ebp\n"
		"\tadd dx, di\n"
		"\tadd dh, cl\n"
		"\tpop DWORD[esp+0xFFDDAA56]\n"
		"\tint 0x03\n"
		"\tint 0x16\n"
		"\t$_SECOND_LABEL_end\n"
		"_THIRD_AND_LAST@@_LABEL:\n"
		"\tret\n"
		"[SECTION .DATA]\n"
		"string_to_be_printed: db 'ImanAbdollahzadehLiBOS'\n"
		"_rgb@@mask_black:     dd  0x23AB8FC6\n"
		"libos_word_data:      dw  0x8F7A\n"
		"simd_operation_rgba:  dX  0xFF000000FF111111FF222222FF33333333\n"
		"_@@an_example_qword:  dq  0x112233445678AEF0\n";
	
	parse_0(file, &tp, &lines, p);
	
	print_file(file);
	
	parse_1_or__convert_instructions_line_by_line(tp, lines);
	dump_table_of_labels();
	zero_programCounter();
	zero_data_section_identifier();
	
	IMAGE_FILE_MEMORY ifm;
	parse_2(tp, lines);
	ifm.total_sizeof_image = get_programCounter();
	image_file_make(tp, lines, &ifm);
	dump_table_of_labels();
	dump_image_file_memory(&ifm);
	dump_output_beffer();
	dump_data_section_table_entries();
	dump_numeric_table();
}

