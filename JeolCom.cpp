#include "JeolCom.h"

#include <cstdlib>

#include <iostream>

#import "TemExt64.dll" named_guids

using namespace TEMEXTLib;
using namespace std;

string BSTR_to_string(BSTR bstr);
string BSTR_to_string(BSTR bstr)
{
	std::wstring w = bstr;
	string s(w.begin(), w.end());
	return s;
}

JeolCom::JeolCom() :connected(false)
{
}

bool JeolCom::Initialize()
{
	if (connected)
		return true;

	CoInitialize(NULL);

	HRESULT hr = CoCreateInstance(__uuidof(TEM3), 0, CLSCTX_ALL, __uuidof(ITEM3),
		(void **)&Instrument);
	if (hr != S_OK)
	{
		return false;
	}

	Sleep(1000);
	connected = true;
	return true;
}

void JeolCom::Create()
{
	if (!connected)
		return;

	HT = Instrument->CreateHT3();
	Gun = Instrument->CreateGUN3();
	Eos = Instrument->CreateEOS3();
	Lens = Instrument->CreateLens3();
	Def = Instrument->CreateDef3();
	Stage = Instrument->CreateStage3();
	Detector = Instrument->CreateDetector3();
	Scan = Instrument->CreateScan3();
	Camera = Instrument->CreateCamera3();

	Aperture = Instrument->CreateApt3();
	Feg = Instrument->CreateFEG3();
	Filter = Instrument->CreateFilter3();
	MDS = Instrument->CreateMDS3();

	Screen = Instrument->CreateScreen1();
}

bool JeolCom::Connect()
{
	if(!Initialize())
		return false;
	Sleep(1000);

	Create();
	Sleep(1000);

	return true;
}

void JeolCom::Release()
{
	if (!connected)
		return;

	HT->Release();
	Gun->Release();
	Eos->Release();
	Lens->Release();
	Def->Release();
	Stage->Release();
	Detector->Release();
	Scan->Release();
	Camera->Release();

	Aperture->Release();
	Feg->Release();
	Filter->Release();
	MDS->Release();
	Instrument->Release();
	//Screen->Release();


}

void JeolCom::Uninitialize()
{
	if (!connected) return;
	CoUninitialize();
	connected = false;
}

void JeolCom::Disconnect()
{
	Release();//Causes the process to end, but gives an error when DM quitting.
	Uninitialize();
}

short JeolCom::HT3SetHtValue(float val)
{
	return getInstance().HT->SetHtValue(val);
}

short JeolCom::HT3GetHtValue(float* val)
{
	return getInstance().HT->GetHtValue(val);
}

short JeolCom::HT3GetHtRange(float* maxValue, float* minStep)
{
	return getInstance().HT->GetHtRange(maxValue, minStep);
}

short JeolCom::GUN3SetFilamentVal(float val)
{
	return getInstance().Gun->SetFilamentVal(val);
}

short JeolCom::GUN3GetFilamentVal(float* val)
{
	return getInstance().Gun->GetFilamentVal(val);
}

short JeolCom::GUN3GetHtStts(short* sw)
{
	return getInstance().Gun->GetHtStts(sw);
}

short JeolCom::GUN3SetBeamSw(short sw)
{
	return getInstance().Gun->SetBeamSw(sw);
}

short JeolCom::GUN3GetBeamSw(short* sw)
{
	return getInstance().Gun->GetBeamSw(sw);
}

short JeolCom::FEG3SetBeamValve(short sw)
{
	return getInstance().Feg->SetBeamValve(sw);
}

short JeolCom::FEG3GetBeamValve(short* sw)
{
	return getInstance().Feg->GetBeamValve(sw);
}

short JeolCom::EOS3SelectTemStem(short mode)
{
	return getInstance().Eos->SelectTemStem(mode);
}

short JeolCom::EOS3GetTemStemMode(short* mode)
{
	return getInstance().Eos->GetTemStemMode(mode);
}

short JeolCom::EOS3SelectSpotSize(short size)
{
	return  getInstance().Eos->SelectSpotSize(size);
}

short JeolCom::EOS3GetSpotSize(short* size)
{
	return  getInstance().Eos->GetSpotSize(size);
}

short JeolCom::EOS3SelectProbMode(short mode)
{
	return getInstance().Eos->SelectProbMode(mode);
}

short JeolCom::EOS3GetProbeMode(short* mode,string* name)
{
	BSTR name_bstr;
	short status = getInstance().Eos->GetProbeMode(mode, &name_bstr);
	*name = BSTR_to_string(name_bstr);
	return status;
}

short JeolCom::EOS3SetAlphaSelector(short sel)
{
	return getInstance().Eos->SetAlphaSelector(sel);
}

short JeolCom::EOS3GetAlpha(short* alpha)
{
	return getInstance().Eos->GetAlpha(alpha);
}

short JeolCom::EOS3SelectFunctionMode(short mode)
{
	return getInstance().Eos->SelectFunctionMode(mode);
}

short JeolCom::EOS3GetFunctionMode(short* mode, string* name)
{
	BSTR name_bstr;
	short status = getInstance().Eos->GetFunctionMode(mode, &name_bstr);
	*name = BSTR_to_string(name_bstr);
	return status;
}

short JeolCom::EOS3SetSelector(short sel)
{
	return getInstance().Eos->SetSelector(sel);
}

short JeolCom::EOS3UpSelector()
{
	return getInstance().Eos->UpSelector();
}

short JeolCom::EOS3DownSelector()
{
	return getInstance().Eos->DownSelector();
}


short JeolCom::EOS3GetMagValue(long* mag,string* unit,string* label)
{
	BSTR unit_bstr, label_bstr;
	short status = getInstance().Eos->GetMagValue(mag, &unit_bstr, &label_bstr);
	*unit = BSTR_to_string(unit_bstr);
	*label = BSTR_to_string(label_bstr);
	return status;
}

short JeolCom::EOS3SetMagValue(long magValue)
{
	short selector;

	switch (magValue)
	{
	case 2000:
		selector = 0;
		break;
	case 2500:
		selector = 1;
		break;
	case 3000:
		selector = 2;
		break;
	case 4000:
		selector = 3;
		break;
	case 5000:
		selector = 4;
		break;
	case 6000:
		selector = 5;
		break;
	case 8000:
		selector = 6;
		break;
	case 10000:
		selector = 7;
		break;
	case 12000:
		selector = 8;
		break;
	case 15000:
		selector = 9;
		break;
	case 20000:
		selector = 10;
		break;
	case 25000:
		selector = 11;
		break;
	case 30000:
		selector = 12;
		break;
	case 40000:
		selector = 13;
		break;
	case 50000:
		selector = 14;
		break;
	case 60000:
		selector = 15;
		break;
	case 80000:
		selector = 16;
		break;
	case 100000:
		selector = 17;
		break;
	case 120000:
		selector = 18;
		break;
	case 150000:
		selector = 19;
		break;
	case 200000:
		selector = 20;
		break;
	case 250000:
		selector = 21;
		break;
	case 300000:
		selector = 22;
		break;
	case 400000:
		selector = 23;
		break;
	case 500000:
		selector = 24;
		break;
	case 600000:
		selector = 25;
		break;
	case 800000:
		selector = 26;
		break;
	case 1000000:
		selector = 27;
		break;
	case 1200000:
		selector = 28;
		break;
	case 1500000:
		selector = 29;
		break;
	default:
		return false;
	}

	return getInstance().Eos->SetSelector(selector);
}

short JeolCom::EOS3SetSpctrMode(short mode)
{
	return getInstance().Eos->SetSpctrMode(mode);
}

short JeolCom::EOS3GetSpctrMode(short* mode)
{
	return getInstance().Eos->GetSpctrMode(mode);
}

short JeolCom::EOS3SetSpctrSelector(short sel)
{
	return getInstance().Eos->SetSpctrSelector(sel);
}

short JeolCom::EOS3UpSpctrSelector()
{
	return getInstance().Eos->UpSpctrSelector();
}

short JeolCom::EOS3DownSpctrSelector()
{
	return getInstance().Eos->DownSpctrSelector();
}

short JeolCom::EOS3GetSpctrValue(long* dispersion,string* unit,string* label)
{
	BSTR unit_bstr, label_bstr;
	short status = getInstance().Eos->GetSpctrValue(dispersion, &unit_bstr, &label_bstr);
	*unit = BSTR_to_string(unit_bstr);
	*label = BSTR_to_string(label_bstr);
	return status;
}

short JeolCom::EOS3SetStemCamSelector(short sel)
{
	return getInstance().Eos->SetStemCamSelector(sel);
}

short JeolCom::EOS3UpStemCamSelector()
{
	return getInstance().Eos->UpStemCamSelector();;
}

short JeolCom::EOS3DownStemCamSelector()
{
	return getInstance().Eos->DownStemCamSelector();
}

short JeolCom::EOS3GetStemCamValue(long* cam,string* unit,string* label)
{
	BSTR unit_bstr, label_bstr;
	short status = getInstance().Eos->GetStemCamValue(cam, &unit_bstr, &label_bstr);
	*unit = BSTR_to_string(unit_bstr);
	*label = BSTR_to_string(label_bstr);
	return status;
}

short JeolCom::EOS3SetBrightness(short relval)
{
	return getInstance().Eos->SetBrightness(relval);
}

short JeolCom::EOS3SetObjFocus(short relval)
{
	return getInstance().Eos->SetObjFocus(relval);
}

short JeolCom::EOS3SetDiffFocus(short relval)
{
	return getInstance().Eos->SetDiffFocus(relval);
}

short JeolCom::LENS3SetCL3(long val)
{
	return getInstance().Lens->SetCL3(val);
}

short JeolCom::LENS3SetOLf(long val)
{
	return getInstance().Lens->SetOLf(val);
}

short JeolCom::LENS3SetOLc(long val)
{
	return getInstance().Lens->SetOLc(val);
}

short JeolCom::LENS3SetOM(long val)
{
	return getInstance().Lens->SetOM(val);
}

short JeolCom::LENS3SetDiffFocus(long val)
{
	return getInstance().Lens->SetDiffFocus(val);
}

short JeolCom::LENS3SetILFocus(long val)
{
	return getInstance().Lens->SetILFocus(val);
}

short JeolCom::LENS3SetPLFocus(long val)
{
	return getInstance().Lens->SetPLFocus(val);
}

short JeolCom::LENS3SetFLf(long val)
{
	return getInstance().Lens->SetFLf(val);
}

short JeolCom::LENS3SetFLc(long val)
{
	return getInstance().Lens->SetFLc(val);
}

short JeolCom::LENS3SetNtrl(short lens)
{
	return getInstance().Lens->SetNtrl(lens);
}

short JeolCom::LENS3GetCL1(long* val)
{
	return getInstance().Lens->GetCL1(val);
}

short JeolCom::LENS3GetCL2(long* val)
{
	return getInstance().Lens->GetCL2(val);;
}

short JeolCom::LENS3GetCL3(long* val)
{
	return getInstance().Lens->GetCL3(val);
}

short JeolCom::LENS3GetCM(long* val)
{
	return getInstance().Lens->GetCM(val);
}

short JeolCom::LENS3GetOLf(long* val)
{
	return getInstance().Lens->GetOLf(val);
}

short JeolCom::LENS3GetOLc(long* val)
{
	return getInstance().Lens->GetOLc(val);
}

short JeolCom::LENS3GetOM(long* val)
{
	return getInstance().Lens->GetOM(val);
}

short JeolCom::LENS3GetOM2(long* val)
{
	return getInstance().Lens->GetOM2(val);
}

short JeolCom::LENS3GetOM2Flag(short* flag)
{
	return getInstance().Lens->GetOM2Flag(flag);
}

short JeolCom::LENS3GetIL1(long* val)
{
	return getInstance().Lens->GetIL1(val);
}

short JeolCom::LENS3GetIL2(long* val)
{
	return getInstance().Lens->GetIL2(val);
}

short JeolCom::LENS3GetIL3(long* val)
{
	return getInstance().Lens->GetIL3(val);
}

short JeolCom::LENS3GetIL4(long* val)
{
	return getInstance().Lens->GetIL4(val);
}

short JeolCom::LENS3GetPL1(long* val)
{
	return getInstance().Lens->GetPL1(val);
}

short JeolCom::LENS3GetPL2(long* val)
{
	return getInstance().Lens->GetPL2(val);
}

short JeolCom::LENS3GetPL3(long* val)
{
	return getInstance().Lens->GetPL3(val);
}

short JeolCom::LENS3GetFLf(long* val)
{
	return getInstance().Lens->GetFLf(val);
}

short JeolCom::LENS3GetFLc(long* val)
{
	return getInstance().Lens->GetFLc(val);
}

short JeolCom::LENS3GetFLcomp1(long* val)
{
	return getInstance().Lens->GetFLcomp1(val);
}

short JeolCom::LENS3GetFLcomp2(long* val)
{
	return getInstance().Lens->GetFLcomp2(val);
}

short JeolCom::DEF3SetGunA1(long x, long y)
{
	return getInstance().Def->SetGunA1(x, y);
}

short JeolCom::DEF3SetGunA2(long x, long y)
{
	return getInstance().Def->SetGunA2(x, y);
}

short JeolCom::DEF3SetSpotA(long x, long y)
{
	return getInstance().Def->SetSpotA(x, y);
}

short JeolCom::DEF3SetCLA1(long x, long y)
{
	return getInstance().Def->SetCLA1(x, y);
}

short JeolCom::DEF3SetCLA2(long x, long y)
{
	return getInstance().Def->SetCLA2(x, y);
}

short JeolCom::DEF3SetCLs(long x, long y)
{
	return getInstance().Def->SetCLs(x, y);
}

short JeolCom::DEF3SetOLs(long x, long y)
{
	return getInstance().Def->SetOLs(x, y);
}

short JeolCom::DEF3SetILs(long x, long y)
{
	return getInstance().Def->SetILs(x, y);
}

short JeolCom::DEF3SetIS1(long x, long y)
{
	return getInstance().Def->SetIS1(x, y);
}

short JeolCom::DEF3SetIS2(long x, long y)
{
	return getInstance().Def->SetIS2(x, y);
}

short JeolCom::DEF3SetFLA1(long x, long y)
{
	return getInstance().Def->SetFLA1(x, y);
}

short JeolCom::DEF3SetFLA2(long x, long y)
{
	return getInstance().Def->SetFLA2(x, y);

}

short JeolCom::DEF3SetFLs1(long x, long y)
{
	return getInstance().Def->SetFLs1(x, y);

}

short JeolCom::DEF3SetFLs2(long x, long y)
{
	return getInstance().Def->SetFLs2(x, y);

}

short JeolCom::DEF3SetPLA(long x, long y)
{
	return getInstance().Def->SetPLA(x, y);

}

short JeolCom::DEF3SetShifBal(long x, long y)
{
	return getInstance().Def->SetShifBal(x, y);

}

short JeolCom::DEF3SetTiltBal(long x, long y)
{
	return getInstance().Def->SetTiltBal(x, y);
}

short JeolCom::DEF3SetAngBal(long x, long y)
{
	return getInstance().Def->SetAngBal(x, y);
}

short JeolCom::DEF3SetDetAlign(short id, long x, long y)
{
	return getInstance().Def->SetDetAlign(id, x, y);
}

short JeolCom::DEF3SetScan1(long x, long y)
{
	return getInstance().Def->SetScan1(x, y);
}

short JeolCom::DEF3SetScan2(long x, long y)
{
	return getInstance().Def->SetScan2(x, y);
}

short JeolCom::DEF3SetStemIS(long x, long y)
{
	return getInstance().Def->SetStemIS(x, y);
}

short JeolCom::DEF3SetDefNtrl(short def)
{
	return getInstance().Def->SetNtrl(def);
}

short JeolCom::DEF3GetGunA1(long* x, long* y)
{
	return getInstance().Def->GetGunA1(x, y);
}

short JeolCom::DEF3GetGunA2(long* x, long* y)
{
	return getInstance().Def->GetGunA2(x, y);
}

short JeolCom::DEF3GetSpotA(long* x, long* y)
{
	return getInstance().Def->GetSpotA(x, y);
}

short JeolCom::DEF3GetCLA1(long* x, long* y)
{
	return getInstance().Def->GetCLA1(x, y);
}

short JeolCom::DEF3GetCLA2(long* x, long* y)
{
	return getInstance().Def->GetCLA2(x, y);
}

short JeolCom::DEF3GetCLs(long* x, long* y)
{
	return getInstance().Def->GetCLs(x, y);
}

short JeolCom::DEF3GetOLs(long* x, long* y)
{
	return getInstance().Def->GetOLs(x, y);
}

short JeolCom::DEF3GetILs(long* x, long* y)
{
	return getInstance().Def->GetILs(x, y);
}

short JeolCom::DEF3GetIS1(long* x, long* y)
{
	return getInstance().Def->GetIS1(x, y);
}

short JeolCom::DEF3GetIS2(long* x, long* y)
{
	return getInstance().Def->GetIS2(x, y);
}

short JeolCom::DEF3GetFLA1(long* x, long* y)
{
	return getInstance().Def->GetFLA1(x, y);
}

short JeolCom::DEF3GetFLA2(long* x, long* y)
{
	return getInstance().Def->GetFLA2(x, y);
}

short JeolCom::DEF3GetFLs1(long* x, long* y)
{
	return getInstance().Def->GetFLs1(x, y);
}

short JeolCom::DEF3GetFLs2(long* x, long* y)
{
	return getInstance().Def->GetFLs2(x, y);
}

short JeolCom::DEF3GetPLA(long* x, long* y)
{
	return getInstance().Def->GetPLA(x, y);
}

short JeolCom::DEF3GetDetAlign(short id, long* x, long* y)
{
	return getInstance().Def->GetDetAlign(id, x, y);
}

short JeolCom::DEF3GetShifBal(long* x, long* y)
{
	return getInstance().Def->GetShifBal(x, y);
}

short JeolCom::DEF3GetTiltBal(long* x, long* y)
{
	return getInstance().Def->GetTiltBal(x, y);
}

short JeolCom::DEF3GetAngBal(long* x, long* y)
{
	return getInstance().Def->GetAngBal(x, y);
}

short JeolCom::DEF3GetScan1(long* x, long* y)
{
	return getInstance().Def->GetScan1(x, y);
}

short JeolCom::DEF3GetScan2(long* x, long* y)
{
	return getInstance().Def->GetScan2(x, y);
}

short JeolCom::DEF3GetStemIS(long* x, long* y)
{
	return getInstance().Def->GetStemIS(x, y);
}

short JeolCom::DEF3SetBeamBlank(short sw)
{
	return getInstance().Def->SetBeamBlank(sw);
}

short JeolCom::DEF3GetBeamBlank(short* sw)
{
	return getInstance().Def->GetBeamBlank(sw);
}

short JeolCom::EFILTER3SetEnergyShift(float val)
{
	return getInstance().Filter->SetEnergyShift(val);
}

short JeolCom::EFILTER3GetEnergyShift(float* val)
{
	return getInstance().Filter->GetEnergyShift(val);
}

short JeolCom::EFILTER3GetEnergyShiftRange(float* max, float* step)
{
	return getInstance().Filter->GetEnergyShiftRange(max, step);
}

short JeolCom::EFILTER3SetEnergyShiftSw(short sw)
{
	return getInstance().Filter->SetEnergyShiftSw(sw);
}

short JeolCom::EFILTER3GetEnergyShiftSw(short* sw)
{
	return getInstance().Filter->GetEnergyShiftSw(sw);
}

short JeolCom::EFILTER3SetSlitWidth(float width)
{
	return getInstance().Filter->SetSlitWidth(width);
}

short JeolCom::EFILTER3GetSlitWidth(float* width)
{
	return getInstance().Filter->GetSlitWidth(width);
}

short JeolCom::EFILTER3SetSlitPosition(short inout)
{
	return getInstance().Filter->SetSlitPosition(inout);
}

short JeolCom::EFILTER3GetSlitPosition(short* pos)
{
	return getInstance().Filter->GetSlitPosition(pos);
}

short JeolCom::EFILTER3GetSlitWidthRange(float* max, float* step)
{
	return getInstance().Filter->GetSlitWidthRange(max, step);
}

short JeolCom::STAGE3SetStagePosition(float x, float y)
{
	return getInstance().Stage->SetPosition(x, y);
}

short JeolCom::STAGE3SetX(float x)
{
	return getInstance().Stage->SetX(x);
}

short JeolCom::STAGE3SetY(float y)
{
	return getInstance().Stage->SetY(y);
}

short JeolCom::STAGE3SetZ(float z)
{
	return getInstance().Stage->SetZ(z);
}

short JeolCom::STAGE3SetTiltXAngle(float tiltx)
{
	return getInstance().Stage->SetTiltXAngle(tiltx);
}

short JeolCom::STAGE3SetTiltYAngle(float angle)
{
	return getInstance().Stage->SetTiltYAngle(angle);
}

short JeolCom::STAGE3SetXRel(float relx)
{
	return getInstance().Stage->SetXRel(relx);
}

short JeolCom::STAGE3SetYRel(float rely)
{
	return getInstance().Stage->SetYRel(rely);
}

short JeolCom::STAGE3SetZRel(float relz)
{
	return getInstance().Stage->SetZRel(relz);
}

short JeolCom::STAGE3SetTXRel(float reltx)
{
	return getInstance().Stage->SetTXRel(reltx);
}

short JeolCom::STAGE3SetTYRel(float ty)
{
	return getInstance().Stage->SetTYRel(ty);
}

short JeolCom::STAGE3SetOrg()
{
	return getInstance().Stage->SetOrg();
}

short JeolCom::STAGE3SelDrvMode(short sw)
{
	return getInstance().Stage->SelDrvMode(sw);
}

short JeolCom::STAGE3GetDrvMode(short* sw)
{
	return getInstance().Stage->GetDrvMode(sw);
}

short JeolCom::STAGE3Stop()
{
	return getInstance().Stage->Stop();
}

short JeolCom::STAGE3GetPos(float* x, float* y, float* z, float* tx, float* ty)
{
	return getInstance().Stage->GetPos(x, y, z, tx, ty);
}

short JeolCom::STAGE3GetStatus(short* x, short* y, short* z, short* tx, short* ty)
{
	return getInstance().Stage->GetStatus(x, y, z, tx, ty);
}

short JeolCom::STAGE3GetDirection(short* x, short* y, short* z, short* tx, short* ty)
{
	return getInstance().Stage->GetDirection(x, y, z, tx, ty);
}

short JeolCom::STAGE3GetPiezoPosi(float* x, float* y)
{
	return getInstance().Stage->GetPiezoPosi(x, y);
}

short JeolCom::STAGE3GetHolderStts(short* stts)
{
	return getInstance().Stage->GetHolderStts(stts);
}

short JeolCom::DETECTOR3SetScreen(short sw)
{
	return getInstance().Detector->SetScreen(sw);
}

short JeolCom::DETECTOR3SetPosition(short code, short position)
{
	return getInstance().Detector->SetPosition(code, position);
}

short JeolCom::DETECTOR3GetPosition(short code, short* position)
{
	return getInstance().Detector->GetPosition(code, position);
}

short JeolCom::DETECTOR3SetImageSw(short code, short sw)
{
	return getInstance().Detector->SetImageSw(code, sw);
}

short JeolCom::DETECTOR3GetImageSw(short code, short* sw)
{
	return getInstance().Detector->GetImageSw(code, sw);
}

short JeolCom::DETECTOR3SetBrt(short code, short val)
{
	return getInstance().Detector->SetBrt(code, val);
}

short JeolCom::DETECTOR3GetBrt(short code, short* val)
{
	return getInstance().Detector->GetBrt(code, val);
}

short JeolCom::DETECTOR3SetCont(short code, short val)
{
	return getInstance().Detector->SetCont(code, val);
}

short JeolCom::DETECTOR3GetCont(short code, short* val)
{
	return getInstance().Detector->GetCont(code, val);
}

short JeolCom::APT3GetKind(short* id)
{
	return getInstance().Aperture->GetKind(id);
}

short JeolCom::APT3SelectKind(short id)
{
	return getInstance().Aperture->SelectKind(id);
}

short JeolCom::APT3GetPosition(short* x, short* y)
{
	return getInstance().Aperture->GetPosition(x, y);
}

short JeolCom::APT3SetPosition(short x, short y)
{
	return getInstance().Aperture->SetPosition(x, y);
}

short JeolCom::APT3GetSize(short kind, short* num)
{
	return getInstance().Aperture->GetSize(kind, num);
}

short JeolCom::APT3SetSize(short num)
{
	return getInstance().Aperture->SetSize(num);
}

short JeolCom::SCAN3SetExtScanMode(short sw)
{
	return getInstance().Scan->SetExtScanMode(sw);
}

short JeolCom::SCAN3GetExtScanMode(short* sw)
{
	return getInstance().Scan->GetExtScanMode(sw);
}

short JeolCom::SCAN3GetRotationAngle(short* angle)
{
	return getInstance().Scan->GetRotationAngle(angle);
}

short JeolCom::SCAN3SetRotationAngle(short angle)
{
	return getInstance().Scan->SetRotationAngle(angle);
}

short JeolCom::CAMERA3SetExpTime(float time)
{
	return getInstance().Camera->SetExpTime(time);
}

short JeolCom::CAMERA3GetExpTime(float* time)
{
	return getInstance().Camera->GetExpTime(time);
}

short JeolCom::CAMERA3SelectFilmLoadingMode(short film_feed)
{
	return getInstance().Camera->SelectFilmLoadingMode(film_feed);
}

short JeolCom::CAMERA3TakePhoto()
{
	return getInstance().Camera->TakePhoto();
}

short JeolCom::CAMERA3CancelPhoto()
{
	return getInstance().Camera->CancelPhoto();
}

short JeolCom::CAMERA3GetStatus(short* stts)
{
	return getInstance().Camera->GetStatus(stts);
}

short JeolCom::CAMERA3SelectMode(short shutter_mode)
{
	return getInstance().Camera->SelectMode(shutter_mode);
}

short JeolCom::CAMERA3GetMode(short* shutter_mode)
{
	return getInstance().Camera->GetMode(shutter_mode);
}

short JeolCom::CAMERA3GetCurrentDensity(float* value)
{
	return getInstance().Camera->GetCurrentDensity(value);
}

short JeolCom::CAMERA3SetShutterPosition(short sw)
{
	return getInstance().Camera->SetShutterPosition(sw);
}

short JeolCom::CAMERA3GetShutterPosition(short* sw)
{
	return getInstance().Camera->GetShutterPosition(sw);
}

short JeolCom::CAMERA3ExposeShutter(float time)
{
	return getInstance().Camera->ExposeShutter(time);
}

short JeolCom::MDS3SetSearchMode()
{
	return getInstance().MDS->SetSearchMode();
}

short JeolCom::MDS3SetFocusMode()
{
	return getInstance().MDS->SetFocusMode();
}

short JeolCom::MDS3SetPhotosetMode()
{
	return getInstance().MDS->SetPhotosetMode();
}

short JeolCom::MDS3EndMdsMode()
{
	return getInstance().MDS->EndMdsMode();
}

short JeolCom::MDS3GetMdsMode(short* mode)
{
	return getInstance().MDS->GetMdsMode(mode);
}

short JeolCom::TEM3CheckEnabled()
{
	return getInstance().Instrument->CheckEnabled();
}

short JeolCom::TEM3SetRecvTimeout(long timer)
{
	return getInstance().Instrument->SetRecvTimeout(timer);
}

short JeolCom::SCREEN1SetAngle(short sw)
{
	return getInstance().Screen->SelectAngle(sw);
}

short JeolCom::SCREEN1GetAngle(short *sw)
{
	return getInstance().Screen->GetAngle(sw);
}
