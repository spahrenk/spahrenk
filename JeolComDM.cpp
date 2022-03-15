#include "stdafxDM.h"

#include "JeolComDM.h"

using namespace Gatan;

void JeolComDM::Connect()
{
	bool status = false;
	PLUG_IN_ENTRY
	status =JeolCom::getInstance().Connect();
	if(status)
		DM::Result("Connected\n");
	else
		DM::Result("Connection failed\n");
	PLUG_IN_EXIT
	//return status;
}

void JeolComDM::Disconnect()
{
	PLUG_IN_ENTRY
	JeolCom::getInstance().Disconnect();
	DM::Result("Disconnected\n");
	PLUG_IN_EXIT
}

short JeolComDM::HT3SetHtValue(float val)
{
	short status=-1;
	PLUG_IN_ENTRY
	status=JeolCom::HT3SetHtValue(val);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::HT3GetHtValue(float* val)
{
	short status=-1;
	PLUG_IN_ENTRY
	status= JeolCom::HT3GetHtValue(val);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::HT3GetHtRange(float* maxValue, float* minStep)
{
	short status = -1;
	PLUG_IN_ENTRY
	status= JeolCom::HT3GetHtRange(maxValue, minStep);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::GUN3SetFilamentVal(float val)
{
	short status=-1;
	PLUG_IN_ENTRY
	status= JeolCom::GUN3SetFilamentVal(val);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::GUN3GetFilamentVal(float* val)
{
	short status=-1;
	PLUG_IN_ENTRY
		status=JeolCom::GUN3GetFilamentVal(val);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::GUN3GetHtStts(short* sw)
{
	short status = -1;
	PLUG_IN_ENTRY
		status=JeolCom::GUN3GetHtStts(sw);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::GUN3SetBeamSw(short sw)
{
	short status = -1;
	PLUG_IN_ENTRY
	status=JeolCom::GUN3SetBeamSw(sw);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::GUN3GetBeamSw(short* sw)
{
	short status = -1;
	PLUG_IN_ENTRY
	status = JeolCom::GUN3GetBeamSw(sw);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::FEG3SetBeamValve(short sw)
{
	short status = -1;
	PLUG_IN_ENTRY
	status = JeolCom::FEG3SetBeamValve(sw);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::FEG3GetBeamValve(short* sw)
{
	short status = -1;
	PLUG_IN_ENTRY
	status=JeolCom::FEG3GetBeamValve(sw);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3SelectTemStem(short mode)
{
	short status = -1;
	PLUG_IN_ENTRY
	status= JeolCom::EOS3SelectTemStem(mode);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3GetTemStemMode(short* mode)
{
	short status = -1;
	PLUG_IN_ENTRY
	status= JeolCom::EOS3GetTemStemMode(mode);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3SelectSpotSize(short size)
{
	short status = -1;
	PLUG_IN_ENTRY
	status= JeolCom::EOS3SelectSpotSize(size);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3GetSpotSize(short* size)
{
	short status = -1;
	PLUG_IN_ENTRY
	status= JeolCom::EOS3GetSpotSize(size);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3SelectProbMode(short mode)
{
	short status = -1;
	PLUG_IN_ENTRY
	status= JeolCom::EOS3SelectProbMode(mode);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3GetProbeMode(short* mode, DM_StringToken* name)
{
	short status = -1;
	string name_str;
	PLUG_IN_ENTRY
	status= JeolCom::EOS3GetProbeMode(mode,&name_str);
	DM::String name_dmstr(name_str);
	DM::String::assign_ptr(*name,name_dmstr.get());
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3SetAlphaSelector(short sel)
{
	short status = -1;
	PLUG_IN_ENTRY
	status = JeolCom::EOS3SetAlphaSelector(sel);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3GetAlpha(short* alpha)
{
	short status = -1;
	PLUG_IN_ENTRY
	status = JeolCom::EOS3GetAlpha(alpha);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3SelectFunctionMode(short mode)
{
	short status = -1;
	PLUG_IN_ENTRY
	status= JeolCom::EOS3SelectFunctionMode(mode);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3GetFunctionMode(short* mode, DM_StringToken* name)
{
	short status = -1;
	string name_str;
	PLUG_IN_ENTRY
	status = JeolCom::EOS3GetFunctionMode(mode,&name_str);
	DM::String name_dmstr(name_str);
	DM::String::assign_ptr(*name, name_dmstr.get());
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3SetSelector(short sel)
{
	short status = -1;
	PLUG_IN_ENTRY
	status = JeolCom::EOS3SetSelector(sel);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3UpSelector()
{
	short status = -1;
	PLUG_IN_ENTRY
	status = JeolCom::EOS3UpSelector();
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3DownSelector()
{
	short status = -1;
	PLUG_IN_ENTRY
	status = JeolCom::EOS3DownSelector();
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3GetMagValue(long* mag, DM_StringToken* unit, DM_StringToken* label)
{
	short status = -1;
	string unit_str,label_str;
	PLUG_IN_ENTRY
	status = JeolCom::EOS3GetMagValue(mag,&unit_str,&label_str);
	DM::String unit_dmstr(unit_str),label_dmstr(label_str);

	DM::String::assign_ptr(*unit,unit_dmstr.get());
	DM::String::assign_ptr(*label,label_dmstr.get());
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3SetMagValue(long magValue)
{
	short status = -1;
	PLUG_IN_ENTRY
	status= JeolCom::EOS3SetMagValue(magValue);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3SetSpctrMode(short mode)
{
	short status = -1;
	PLUG_IN_ENTRY
	status= JeolCom::EOS3SetSpctrMode(mode);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3GetSpctrMode(short* mode)
{
	short status = -1;
	PLUG_IN_ENTRY
	status= JeolCom::EOS3GetSpctrMode(mode);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3SetSpctrSelector(short sel)
{
	short status = -1;
	PLUG_IN_ENTRY
	status= JeolCom::EOS3SetSpctrSelector(sel);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3UpSpctrSelector()
{
	short status = -1;
	PLUG_IN_ENTRY
	status = JeolCom::EOS3UpSpctrSelector();
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3DownSpctrSelector()
{
	short status = -1;
	PLUG_IN_ENTRY
	status = JeolCom::EOS3DownSpctrSelector();
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3GetSpctrValue(long* dispersion, DM_StringToken* unit, DM_StringToken* label)
{
	short status = -1;
	string unit_str,label_str;
	PLUG_IN_ENTRY
	status = JeolCom::EOS3GetSpctrValue(dispersion,&unit_str,&label_str);
	DM::String unit_dmstr(unit_str),label_dmstr(label_str);

	DM::String::assign_ptr(*unit,unit_dmstr.get());
	DM::String::assign_ptr(*label,label_dmstr.get());
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3SetStemCamSelector(short sel)
{
	short status = -1;
	PLUG_IN_ENTRY
	status = JeolCom::EOS3SetStemCamSelector(sel);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3UpStemCamSelector()
{
	short status = -1;
	PLUG_IN_ENTRY
	status = JeolCom::EOS3UpStemCamSelector();
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3DownStemCamSelector()
{
	short status = -1;
	PLUG_IN_ENTRY
	status = JeolCom::EOS3DownStemCamSelector();
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3GetStemCamValue(long* cam, DM_StringToken* unit, DM_StringToken* label)
{
	short status = -1;
	string unit_str,label_str;
	PLUG_IN_ENTRY
	status= JeolCom::EOS3GetStemCamValue(cam,&unit_str,&label_str);
	DM::String unit_dmstr(unit_str),label_dmstr(label_str);

	DM::String::assign_ptr(*unit, unit_dmstr.get());
	DM::String::assign_ptr(*label, label_dmstr.get());
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3SetBrightness(short relval)
{
	short status = -1;
	PLUG_IN_ENTRY
	status = JeolCom::EOS3SetBrightness(relval);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3SetObjFocus(short relval)
{
	short status = -1;
	PLUG_IN_ENTRY
	status = JeolCom::EOS3SetObjFocus(relval);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::EOS3SetDiffFocus(short relval)
{
	short status = -1;
	PLUG_IN_ENTRY
	status=JeolCom::EOS3SetDiffFocus(relval);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::LENS3SetCL3(long val)
{
	short status = -1;
	PLUG_IN_ENTRY
	status= JeolCom::LENS3SetCL3(val);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::LENS3SetOLf(long val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3SetOLf(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3SetOLc(long val)
{
	short status = -1;
	PLUG_IN_ENTRY
	status= JeolCom::LENS3SetOLc(val);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::LENS3SetOM(long val)
{
	short status = -1;
	PLUG_IN_ENTRY
	status= JeolCom::LENS3SetOM(val);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::LENS3SetDiffFocus(long val)
{
	short status = -1;
	PLUG_IN_ENTRY
	status = JeolCom::LENS3SetDiffFocus(val);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::LENS3SetILFocus(long val)
{
	short status = -1;
	PLUG_IN_ENTRY
	status= JeolCom::LENS3SetILFocus(val);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::LENS3SetPLFocus(long val)
{
	short status = -1;
	PLUG_IN_ENTRY
	status = JeolCom::LENS3SetPLFocus(val);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::LENS3SetFLf(long val)
{
	short status = -1;
	PLUG_IN_ENTRY
	status = JeolCom::LENS3SetFLf(val);
	PLUG_IN_EXIT
	return status;
}

short JeolComDM::LENS3SetFLc(long val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3SetFLc(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3SetNtrl(short lens)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3SetNtrl(lens);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3GetCL1(long* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3GetCL1(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3GetCL2(long* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3GetCL2(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3GetCL3(long* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3GetCL3(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3GetCM(long* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3GetCM(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3GetOLf(long* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3GetOLf(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3GetOLc(long* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3GetOLc(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3GetOM(long* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3GetOM(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3GetOM2(long* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3GetOM2(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3GetOM2Flag(short* flag)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3GetOM2Flag(flag);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3GetIL1(long* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3GetIL1(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3GetIL2(long* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3GetIL2(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3GetIL3(long* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3GetIL3(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3GetIL4(long* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3GetIL4(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3GetPL1(long* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3GetPL1(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3GetPL2(long* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3GetPL2(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3GetPL3(long* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3GetPL3(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3GetFLf(long* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3GetFLf(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3GetFLc(long* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3GetFLc(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3GetFLcomp1(long* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3GetFLcomp1(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::LENS3GetFLcomp2(long* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::LENS3GetFLcomp2(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetGunA1(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetGunA1(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetGunA2(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetGunA2(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetSpotA(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetSpotA(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetCLA1(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetCLA1(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetCLA2(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetCLA2(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetCLs(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetCLs(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetOLs(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetOLs(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetILs(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetILs(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetIS1(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetIS1(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetIS2(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetIS2(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetFLA1(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetFLA1(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetFLA2(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetFLA2(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetFLs1(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetFLs1(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetFLs2(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetFLs2(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetPLA(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetPLA(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetShifBal(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetShifBal(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetTiltBal(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetTiltBal(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetAngBal(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetAngBal(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetDetAlign(short id, long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetDetAlign(id, x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetScan1(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetScan1(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetScan2(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetScan2(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetStemIS(long x, long y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetStemIS(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetDefNtrl(short def)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetDefNtrl(def);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetGunA1(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetGunA1(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetGunA2(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetGunA2(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetSpotA(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetSpotA(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetCLA1(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetCLA1(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetCLA2(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetCLA2(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetCLs(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetCLs(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetOLs(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetOLs(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetILs(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetILs(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetIS1(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetIS1(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetIS2(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetIS2(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetFLA1(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetFLA1(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetFLA2(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetFLA2(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetFLs1(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetFLs1(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetFLs2(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetFLs2(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetPLA(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetPLA(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetDetAlign(short id, long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetDetAlign(id, x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetShifBal(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetShifBal(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetTiltBal(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetTiltBal(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetAngBal(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetAngBal(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetScan1(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetScan1(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetScan2(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetScan2(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetStemIS(long* x, long* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetStemIS(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3SetBeamBlank(short sw)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3SetBeamBlank(sw);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DEF3GetBeamBlank(short* sw)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DEF3GetBeamBlank(sw);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::EFILTER3SetEnergyShift(float val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::EFILTER3SetEnergyShift(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::EFILTER3GetEnergyShift(float* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::EFILTER3GetEnergyShift(val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::EFILTER3GetEnergyShiftRange(float* max, float* step)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::EFILTER3GetEnergyShiftRange(max, step);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::EFILTER3SetEnergyShiftSw(short sw)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::EFILTER3SetEnergyShiftSw(sw);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::EFILTER3GetEnergyShiftSw(short* sw)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::EFILTER3GetEnergyShiftSw(sw);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::EFILTER3SetSlitWidth(float width)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::EFILTER3SetSlitWidth(width);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::EFILTER3GetSlitWidth(float* width)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::EFILTER3GetSlitWidth(width);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::EFILTER3SetSlitPosotion(short inout)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::EFILTER3SetSlitPosition(inout);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::EFILTER3GetSlitPosition(short* pos)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::EFILTER3GetSlitPosition(pos);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::EFILTER3GetSlitWidthRange(float* max, float* step)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::EFILTER3GetSlitWidthRange(max, step);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::STAGE3SetStagePosition(float x, float y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::STAGE3SetStagePosition(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::STAGE3SetX(float x)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::STAGE3SetX(x);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::STAGE3SetY(float y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::STAGE3SetY(y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::STAGE3SetZ(float z)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::STAGE3SetZ(z);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::STAGE3SetTiltXAngle(float tiltx)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::STAGE3SetTiltXAngle(tiltx);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::STAGE3SetTiltYAngle(float angle)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::STAGE3SetTiltYAngle(angle);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::STAGE3SetXRel(float relx)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::STAGE3SetXRel(relx);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::STAGE3SetYRel(float rely)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::STAGE3SetYRel(rely);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::STAGE3SetZRel(float relz)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::STAGE3SetZRel(relz);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::STAGE3SetTXRel(float reltx)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::STAGE3SetTXRel(reltx);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::STAGE3SetTYRel(float ty)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::STAGE3SetTYRel(ty);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::STAGE3SetOrg()
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::STAGE3SetOrg();
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::STAGE3SelDrvMode(short sw)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::STAGE3SelDrvMode(sw);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::STAGE3GetDrvMode(short* sw)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::STAGE3GetDrvMode(sw);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::STAGE3Stop()
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::STAGE3Stop();
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::STAGE3GetPos(float* x, float* y, float* z, float* tx, float* ty)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::STAGE3GetPos(x, y, z, tx, ty);
	PLUG_IN_EXIT
		return  status;
}

short JeolComDM::STAGE3GetStatus(short* x, short* y, short* z, short* tx, short* ty)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::STAGE3GetStatus(x, y, z, tx, ty);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::STAGE3GetDirection(short* x, short* y, short* z, short* tx, short* ty)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::STAGE3GetDirection(x, y, z, tx, ty);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::STAGE3GetPiezoPosi(float* x, float* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::STAGE3GetPiezoPosi(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::STAGE3GetHolderStts(short* stts)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::STAGE3GetHolderStts(stts);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DETECTOR3SetScreen(short sw)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DETECTOR3SetScreen(sw);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DETECTOR3SetPosition(short code, short position)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DETECTOR3SetPosition(code, position);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DETECTOR3GetPosition(short code, short* position)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DETECTOR3GetPosition(code, position);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DETECTOR3SetImageSw(short code, short sw)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DETECTOR3SetImageSw(code, sw);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DETECTOR3GetImageSw(short code, short* sw)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DETECTOR3GetImageSw(code, sw);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DETECTOR3SetBrt(short code, short val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DETECTOR3SetBrt(code, val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DETECTOR3GetBrt(short code, short* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DETECTOR3GetBrt(code, val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DETECTOR3SetCont(short code, short val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DETECTOR3SetCont(code, val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::DETECTOR3GetCont(short code, short* val)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::DETECTOR3GetCont(code, val);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::APT3GetKind(short* id)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::APT3GetKind(id);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::APT3SelectKind(short id)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::APT3SelectKind(id);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::APT3GetPosition(short* x, short* y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::APT3GetPosition(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::APT3SetPosition(short x, short y)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::APT3SetPosition(x, y);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::APT3GetSize(short kind, short* num)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::APT3GetSize(kind, num);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::APT3SetSize(short num)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::APT3SetSize(num);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::SCAN3SetExtScanMode(short sw)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::SCAN3SetExtScanMode(sw);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::SCAN3GetExtScanMode(short* sw)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::SCAN3GetExtScanMode(sw);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::SCAN3GetRotationAngle(short* angle)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::SCAN3GetRotationAngle(angle);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::SCAN3SetRotationAngle(short angle)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::SCAN3SetRotationAngle(angle);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::CAMERA3SetExpTime(float time)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::CAMERA3SetExpTime(time);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::CAMERA3GetExpTime(float* time)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::CAMERA3GetExpTime(time);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::CAMERA3SelectFilmLoadingMode(short film_feed)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::CAMERA3SelectFilmLoadingMode(film_feed);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::CAMERA3TakePhoto()
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::CAMERA3TakePhoto();
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::CAMERA3CancelPhoto()
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::CAMERA3CancelPhoto();
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::CAMERA3GetStatus(short* stts)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::CAMERA3GetStatus(stts);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::CAMERA3SelectMode(short shutter_mode)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::CAMERA3SelectMode(shutter_mode);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::CAMERA3GetMode(short* shutter_mode)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::CAMERA3GetMode(shutter_mode);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::CAMERA3GetCurrentDensity(float* value)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::CAMERA3GetCurrentDensity(value);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::CAMERA3SetShutterPosition(short sw)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::CAMERA3SetShutterPosition(sw);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::CAMERA3GetShutterPosition(short* sw)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::CAMERA3GetShutterPosition(sw);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::CAMERA3ExposeShutter(float time)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::CAMERA3ExposeShutter(time);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::MDS3SetSearchMode()
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::MDS3SetSearchMode();
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::MDS3SetFocusMode()
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::MDS3SetFocusMode();
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::MDS3SetPhotosetMode()
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::MDS3SetPhotosetMode();
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::MDS3EndMdsMode()
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::MDS3EndMdsMode();
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::MDS3GetMdsMode(short* mode)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::MDS3GetMdsMode(mode);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::TEM3CheckEnabled()
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::getInstance().TEM3CheckEnabled();
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::TEM3SetRecvTimeout(long timer)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::getInstance().TEM3SetRecvTimeout(timer);
	PLUG_IN_EXIT
		return status;
}

short JeolComDM::SCREEN1SetAngle(short sw)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::SCREEN1SetAngle(sw);
	PLUG_IN_EXIT
		return status;
}
short JeolComDM::SCREEN1GetAngle(short *sw)
{
	short status = -1;
	PLUG_IN_ENTRY
		status = JeolCom::SCREEN1GetAngle(sw);
	PLUG_IN_EXIT
		return status;
}