internal void CreateOpcodeIDS_64(file_manager * FileManager)
{

	const eff_bits mod = ZeroesFile(2, BitfieldType_mod);
	const eff_bits reg = ZeroesFile(3, BitfieldType_reg);
	const eff_bits rm = ZeroesFile(3, BitfieldType_rm);
	const eff_bits tttn = ZeroesFile(4, BitfieldType_tttn);
	const eff_bits eee = ZeroesFile(3, BitfieldType_eee);
	const eff_bits sreg2 = ZeroesFile(2, BitfieldType_sreg2);
	const eff_bits sreg3 = ZeroesFile(2, BitfieldType_sreg3);
	const eff_bits s = ZeroesFile(1, BitfieldType_s);
	const eff_bits low_rex = ZeroesFile(4, BitfieldType_low_rex);

	BeginFileSection(FileManager, FileSection_bits_64);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x00));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x02));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x03));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x04));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x05));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x08));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x09));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0C));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0D));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x10));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x11));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x12));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x13));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x14));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x15));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x18));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x19));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1C));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1D));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x20));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x21));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x22));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x23));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x24));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x25));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x28));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x29));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2C));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2D));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2E));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x30));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x31));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x32));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x33));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x34));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x35));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x39));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3C));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3D));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3E));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(5,0x0A));
	CopyBitsToFile(FileManager, reg);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(5,0x0A));
	CopyBitsToFile(FileManager, reg);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(5,0x0B));
	CopyBitsToFile(FileManager, reg);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(5,0x0B));
	CopyBitsToFile(FileManager, reg);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x63));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x63));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x64));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x68));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x69));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6A));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6C));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6D));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6E));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6F));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x70));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x71));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x72));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x73));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x74));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x75));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x76));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x77));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x78));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x79));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7A));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7B));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7C));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7D));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7E));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7F));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x80));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x80));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x80));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x80));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x80));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x80));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x80));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x80));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x81));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x81));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x81));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x81));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x81));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x81));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x81));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x81));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x83));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x83));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x83));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x83));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x83));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x83));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x83));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x83));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x84));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x85));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x86));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x87));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x88));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x89));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x8A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x8B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x8C));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x8C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x8D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x8E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x8F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x8F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x90));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(5,0x12));
	CopyBitsToFile(FileManager, reg);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x90));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x90));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x98));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x99));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9C));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9D));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9E));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9F));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xA0));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xA1));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xA2));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xA3));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xA4));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xA5));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xA6));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xA7));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xA8));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xA9));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAA));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAB));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAC));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAD));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAE));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAF));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(5,0x16));
	CopyBitsToFile(FileManager, reg);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(5,0x17));
	CopyBitsToFile(FileManager, reg);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC2));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC3));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC8));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC8));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC9));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC9));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xCA));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xCB));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xCC));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xCD));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xCE));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xCF));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD3));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD3));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD3));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD3));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD3));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD3));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD3));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD3));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD7));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD8));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD8));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD8));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD8));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD8));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD1));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD8));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD8));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD8));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD8));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD8));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD8));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD8));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD8));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD8));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD8));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD8));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC9));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD0));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE0));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE1));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE4));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE5));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE8));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE9));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEA));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEB));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEC));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xED));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEE));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF0));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF1));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF4));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF5));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF6));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF7));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF8));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF9));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFA));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFB));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFC));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFD));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFE));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFF));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDA));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDA));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDA));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDA));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDA));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE9));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE0));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE0));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE0));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE1));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE1));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE1));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE2));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE2));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE2));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE3));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE3));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE3));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE4));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE4));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE4));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDC));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDC));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDC));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDC));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDC));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDC));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDC));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDC));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDC));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDC));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDC));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDC));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDC));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDC));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDC));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDC));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE1));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE9));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC1));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC9));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE1));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE9));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF1));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF9));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDF));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDF));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDF));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDF));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDF));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE0));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDF));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE0));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDF));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE0));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDF));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDF));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE0));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE1));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE2));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE3));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE4));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE5));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE6));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE7));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE8));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE9));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEB));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEC));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xED));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEE));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEF));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF1));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF4));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF5));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF8));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF9));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFA));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFB));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFC));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFD));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x00));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x00));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x00));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x00));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x00));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x00));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x00));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x00));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x00));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC1));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC2));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC3));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC4));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC8));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC9));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD0));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD1));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF8));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF9));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x02));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x02));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x03));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x03));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x05));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x06));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x07));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x08));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x09));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0B));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x10));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x10));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x10));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x10));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x10));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x10));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x10));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x11));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x11));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x11));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x11));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x11));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x11));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x11));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x12));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x12));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x12));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x12));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x12));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x12));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x12));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x12));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x13));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x13));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x13));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x14));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x14));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x14));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x15));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x15));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x15));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x16));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x16));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x16));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x16));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x16));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x16));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x17));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x17));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x17));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x18));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x18));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x18));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x18));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x18));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x18));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x18));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x18));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x18));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x19));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x20));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x21));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x22));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x23));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x24));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x26));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x28));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x28));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x28));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x29));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x29));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x29));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x30));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x31));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x32));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x33));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x34));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x35));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x37));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x00));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x00));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x00));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x01));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x02));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x02));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x02));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x03));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x03));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x03));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x04));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x04));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x04));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x05));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x05));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x05));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x06));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x06));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x06));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x07));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x07));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x07));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x08));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x08));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x08));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x09));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x09));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x09));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x10));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x10));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x14));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x14));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x15));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x15));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x17));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x17));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x1E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x20));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x20));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x20));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x20));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x21));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x21));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x21));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x21));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x22));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x22));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x22));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x22));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x23));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x23));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x23));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x23));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x24));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x24));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x24));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x24));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x25));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x25));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x25));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x25));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x28));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x28));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x29));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x29));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x2B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x30));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x30));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x30));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x30));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x31));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x31));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x31));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x31));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x32));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x32));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x32));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x32));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x33));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x33));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x33));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x33));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x34));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x34));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x34));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x34));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x35));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x35));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x35));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x35));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x37));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x37));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x39));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x39));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x40));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x40));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x41));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x41));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x80));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x80));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x80));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x80));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x81));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x81));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x81));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x81));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x38));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x08));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x08));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x09));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x09));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x14));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x14));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x14));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x14));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x15));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x15));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x15));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x15));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x16));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x16));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x17));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x17));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x20));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x20));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x20));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x20));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x21));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x21));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x21));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x21));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x22));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x22));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x40));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x40));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x41));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x41));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x42));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x42));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x60));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x60));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x61));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x61));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x62));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x62));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x63));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x3A));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x63));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x40));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x41));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x42));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x43));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x44));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x45));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x46));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x47));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x48));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x49));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x4A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x4B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x4C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x4D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x4E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x4F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x50));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x50));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x50));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x51));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x51));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x51));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x51));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x51));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x51));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x51));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x52));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x52));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x52));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x53));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x53));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x53));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x54));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x54));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x54));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x55));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x55));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x55));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x56));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x56));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x56));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x57));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x57));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x57));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x58));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x58));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x58));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x58));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x58));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x58));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x58));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x59));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x59));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x59));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x59));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x59));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x59));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x59));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x5F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x60));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x60));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x60));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x61));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x61));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x61));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x62));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x62));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x62));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x63));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x63));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x63));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x64));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x64));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x64));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x65));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x65));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x65));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x67));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x67));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x67));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x68));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x68));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x68));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x69));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x69));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x69));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x6F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x70));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x70));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x70));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x70));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x70));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x70));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x70));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x71));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x71));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x71));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x71));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x71));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x71));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x71));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x71));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x71));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x72));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x72));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x72));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x72));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x72));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x72));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x72));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x72));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x72));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x73));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x73));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x73));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x73));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x73));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x73));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x73));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x73));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x73));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x73));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x74));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x74));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x74));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x75));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x75));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x75));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x76));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x76));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x76));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x77));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x78));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x79));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x7F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x80));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x81));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x82));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x83));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x84));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x85));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x86));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x87));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x88));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x89));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x8A));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x8B));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x8C));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x8D));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x8E));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x8F));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x90));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x91));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x92));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x93));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x94));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x95));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x96));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x97));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x98));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x99));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9A));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9B));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9C));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9D));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9E));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x9F));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xA0));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xA1));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xA2));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xA3));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xA4));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xA5));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xA8));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xA9));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAA));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAB));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAC));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAD));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x0));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x2));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x3));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAE));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE8));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAE));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF0));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAE));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF8));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xAF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xB0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xB1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xB2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xB3));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xB4));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xB5));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xB6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xB7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xB8));
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xB8));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xB8));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xB9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xBA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x4));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xBA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x5));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xBA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xBA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xBB));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xBC));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xBD));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xBE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xBF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC3));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC4));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC4));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC4));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC4));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC4));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC4));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC5));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC5));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC5));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x1));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x6));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xC7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, BitsIDFile(3,0x7));
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(5,0x19));
	CopyBitsToFile(FileManager, reg);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD3));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD3));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD3));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD4));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD4));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD4));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD5));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD5));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD5));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD6));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD6));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD6));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD6));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD7));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD7));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD7));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD8));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD8));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD8));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xD9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDB));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDC));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDC));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDC));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDD));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xDF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE3));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE3));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE3));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE4));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE4));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE4));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE5));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE5));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE5));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE7));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE8));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE8));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE8));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xE9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEB));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEB));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEB));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEC));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEC));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEC));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xED));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xED));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xED));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xEF));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF0));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF1));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF2));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF3));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF4));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF4));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF4));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF5));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF5));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF5));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF6));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF7));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF7));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF7));
	CopyBitsToFile(FileManager, BitsIDFile(2,3));
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF8));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF8));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF8));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xF9));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFA));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFB));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFB));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFB));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFC));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFC));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFC));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFD));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFD));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFD));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	BeginInstructionBits(FileManager);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x66));
	CopyBitsToFile(FileManager, BitsIDFile(4,0x4));
	CopyBitsToFile(FileManager, low_rex);
	CopyBitsToFile(FileManager, BitsIDFile(8,0x0F));
	CopyBitsToFile(FileManager, BitsIDFile(8,0xFE));
	CopyBitsToFile(FileManager, mod);
	CopyBitsToFile(FileManager, reg);
	CopyBitsToFile(FileManager, rm);
	EndInstructionBits(FileManager);

	EndFileSection(FileManager);
}