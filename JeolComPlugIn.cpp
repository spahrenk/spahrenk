#include "stdafxDM.h"

#define _GATANPLUGIN_USE_CLASS_PLUGINMAIN
#include "DMPlugInMain.h"

#include "JeolComDM.h"
#include "JeolComPlugIn.h"

using namespace Gatan;


JeolComPlugIn::JeolComPlugIn()
{
}

JeolComPlugIn::~JeolComPlugIn()
{
	JeolComDM::Disconnect();//Seems to avoid DM crashing on exit.
}

void JeolComPlugIn::Start()
{
	DM::Result("Start Jeol Plugin...\n");
	fFunctionList.push_back(AddFunction("void JeolConnect()", (void*)JeolComDM::Connect));
	fFunctionList.push_back(AddFunction("void JeolDisconnect()", (void*)JeolComDM::Disconnect));

	fFunctionList.push_back(AddFunction("short HT3GetHtValue( float* val )", (void*)JeolComDM::HT3GetHtValue));
	fFunctionList.push_back(AddFunction("short HT3SetHtValue( float val )", (void*)JeolComDM::HT3SetHtValue));
	fFunctionList.push_back(AddFunction("short HT3GetHtRange( float* maxValue, float* minStep )", (void*)JeolComDM::HT3GetHtRange));
	fFunctionList.push_back(AddFunction("short GUN3SetFilamentVal( float val )", (void*)JeolComDM::GUN3SetFilamentVal));
	fFunctionList.push_back(AddFunction("short GUN3GetFilamentVal( float* val )", (void*)JeolComDM::GUN3GetFilamentVal));
	fFunctionList.push_back(AddFunction("short GUN3GetHtStts( short* sw )", (void*)JeolComDM::GUN3GetHtStts));
	fFunctionList.push_back(AddFunction("short GUN3SetBeamSw( short sw )", (void*)JeolComDM::GUN3SetBeamSw));
	fFunctionList.push_back(AddFunction("short GUN3GetBeamSw( short* sw)", (void*)JeolComDM::GUN3GetBeamSw));
	fFunctionList.push_back(AddFunction("short FEG3SetBeamValve( short sw )", (void*)JeolComDM::FEG3SetBeamValve));
	fFunctionList.push_back(AddFunction("short FEG3GetBeamValve( short* sw )", (void*)JeolComDM::FEG3GetBeamValve));
	fFunctionList.push_back(AddFunction("short EOS3SelectTemStem( short mode )", (void*)JeolComDM::EOS3SelectTemStem));
	fFunctionList.push_back(AddFunction("short EOS3GetTemStemMode( short* mode)", (void*)JeolComDM::EOS3GetTemStemMode));
	fFunctionList.push_back(AddFunction("short EOS3SelectSpotSize( short size )", (void*)JeolComDM::EOS3SelectSpotSize));
	fFunctionList.push_back(AddFunction("short EOS3GetSpotSize( short* size )", (void*)JeolComDM::EOS3GetSpotSize));
	fFunctionList.push_back(AddFunction("short EOS3SelectProbMode( short mode )", (void*)JeolComDM::EOS3SelectProbMode));
	fFunctionList.push_back(AddFunction("short EOS3GetProbeMode( short* mode, dm_string* name )", (void*)JeolComDM::EOS3GetProbeMode));
	fFunctionList.push_back(AddFunction("short EOS3SetAlphaSelector( short sel )", (void*)JeolComDM::EOS3SetAlphaSelector));
	fFunctionList.push_back(AddFunction("short EOS3GetAlpha( short* alpha )", (void*)JeolComDM::EOS3GetAlpha));
	fFunctionList.push_back(AddFunction("short EOS3SelectFunctionMode( short mode )", (void*)JeolComDM::EOS3SelectFunctionMode));
	fFunctionList.push_back(AddFunction("short EOS3GetFunctionMode( short* mode, dm_string* name )", (void*)JeolComDM::EOS3GetFunctionMode));
	fFunctionList.push_back(AddFunction("short EOS3SetSelector( short sel )", (void*)JeolComDM::EOS3SetSelector));
	fFunctionList.push_back(AddFunction("short EOS3UpSelector()", (void*)JeolComDM::EOS3UpSelector));
	fFunctionList.push_back(AddFunction("short EOS3DownSelector()", (void*)JeolComDM::EOS3DownSelector));
	fFunctionList.push_back(AddFunction("short EOS3GetMagValue( long* mag, dm_string* unit, dm_string* string )", (void*)JeolComDM::EOS3GetMagValue));
	fFunctionList.push_back(AddFunction("short EOS3SetMagValue( long magValue )", (void*)JeolComDM::EOS3SetMagValue));
	fFunctionList.push_back(AddFunction("short EOS3SetSpctrMode( short mode )", (void*)JeolComDM::EOS3SetSpctrMode));
	fFunctionList.push_back(AddFunction("short EOS3GetSpctrMode( short* mode )", (void*)JeolComDM::EOS3GetSpctrMode));
	fFunctionList.push_back(AddFunction("short EOS3SetSpctrSelector( short sel )", (void*)JeolComDM::EOS3SetSpctrSelector));
	fFunctionList.push_back(AddFunction("short EOS3UpSpctrSelector()", (void*)JeolComDM::EOS3UpSpctrSelector));
	fFunctionList.push_back(AddFunction("short EOS3DownSpctrSelector()", (void*)JeolComDM::EOS3DownSpctrSelector));
	fFunctionList.push_back(AddFunction("short EOS3GetSpctrValue( long* dispersion, dm_string* unit, dm_string* string )", (void*)JeolComDM::EOS3GetSpctrValue));
	fFunctionList.push_back(AddFunction("short EOS3SetStemCamSelector( short sel )", (void*)JeolComDM::EOS3SetStemCamSelector));
	fFunctionList.push_back(AddFunction("short EOS3UpStemCamSelector()", (void*)JeolComDM::EOS3UpStemCamSelector));
	fFunctionList.push_back(AddFunction("short EOS3DownStemCamSelector()", (void*)JeolComDM::EOS3DownStemCamSelector));
	fFunctionList.push_back(AddFunction("short EOS3GetStemCamValue( long* cam, dm_string* unit, dm_string* string )", (void*)JeolComDM::EOS3GetStemCamValue));
	fFunctionList.push_back(AddFunction("short EOS3SetBrightness( short relval )", (void*)JeolComDM::EOS3SetBrightness));
	fFunctionList.push_back(AddFunction("short EOS3SetObjFocus( short relval )", (void*)JeolComDM::EOS3SetObjFocus));
	fFunctionList.push_back(AddFunction("short EOS3SetDiffFocus( short relval )", (void*)JeolComDM::EOS3SetDiffFocus));
	fFunctionList.push_back(AddFunction("short LENS3SetCL3( long val )", (void*)JeolComDM::LENS3SetCL3));
	fFunctionList.push_back(AddFunction("short LENS3SetOLf( long val )", (void*)JeolComDM::LENS3SetOLf));
	fFunctionList.push_back(AddFunction("short LENS3SetOLc( long val )", (void*)JeolComDM::LENS3SetOLc));
	fFunctionList.push_back(AddFunction("short LENS3SetOM( long val )", (void*)JeolComDM::LENS3SetOM));
	fFunctionList.push_back(AddFunction("short LENS3SetDiffFocus( long val )", (void*)JeolComDM::LENS3SetDiffFocus));
	fFunctionList.push_back(AddFunction("short LENS3SetILFocus( long val )", (void*)JeolComDM::LENS3SetILFocus));
	fFunctionList.push_back(AddFunction("short LENS3SetPLFocus( long val )", (void*)JeolComDM::LENS3SetPLFocus));
	fFunctionList.push_back(AddFunction("short LENS3SetFLf( long val )", (void*)JeolComDM::LENS3SetFLf));
	fFunctionList.push_back(AddFunction("short LENS3SetFLc( long val )", (void*)JeolComDM::LENS3SetFLc));
	fFunctionList.push_back(AddFunction("short LENS3SetNtrl( short lens )", (void*)JeolComDM::LENS3SetNtrl));
	fFunctionList.push_back(AddFunction("short LENS3GetCL1( long* val )", (void*)JeolComDM::LENS3GetCL1));
	fFunctionList.push_back(AddFunction("short LENS3GetCL2( long* val )", (void*)JeolComDM::LENS3GetCL2));
	fFunctionList.push_back(AddFunction("short LENS3GetCL3( long* val )", (void*)JeolComDM::LENS3GetCL3));
	fFunctionList.push_back(AddFunction("short LENS3GetCM( long* val )", (void*)JeolComDM::LENS3GetCM));
	fFunctionList.push_back(AddFunction("short LENS3GetOLf( long* val )", (void*)JeolComDM::LENS3GetOLf));
	fFunctionList.push_back(AddFunction("short LENS3GetOLc( long* val )", (void*)JeolComDM::LENS3GetOLc));
	fFunctionList.push_back(AddFunction("short LENS3GetOM( long* val )", (void*)JeolComDM::LENS3GetOM));
	fFunctionList.push_back(AddFunction("short LENS3GetOM2( long* val )", (void*)JeolComDM::LENS3GetOM2));
	fFunctionList.push_back(AddFunction("short LENS3GetOM2Flag( short* flag )", (void*)JeolComDM::LENS3GetOM2Flag));
	fFunctionList.push_back(AddFunction("short LENS3GetIL1( long* val )", (void*)JeolComDM::LENS3GetIL1));
	fFunctionList.push_back(AddFunction("short LENS3GetIL2( long* val )", (void*)JeolComDM::LENS3GetIL2));
	fFunctionList.push_back(AddFunction("short LENS3GetIL3( long* val )", (void*)JeolComDM::LENS3GetIL3));
	fFunctionList.push_back(AddFunction("short LENS3GetIL4( long* val )", (void*)JeolComDM::LENS3GetIL4));
	fFunctionList.push_back(AddFunction("short LENS3GetPL1( long* val )", (void*)JeolComDM::LENS3GetPL1));
	fFunctionList.push_back(AddFunction("short LENS3GetPL2( long* val )", (void*)JeolComDM::LENS3GetPL2));
	fFunctionList.push_back(AddFunction("short LENS3GetPL3( long* val )", (void*)JeolComDM::LENS3GetPL3));
	fFunctionList.push_back(AddFunction("short LENS3GetFLf( long* val )", (void*)JeolComDM::LENS3GetFLf));
	fFunctionList.push_back(AddFunction("short LENS3GetFLc( long* val )", (void*)JeolComDM::LENS3GetFLc));
	fFunctionList.push_back(AddFunction("short LENS3GetFLcomp1( long* val )", (void*)JeolComDM::LENS3GetFLcomp1));
	fFunctionList.push_back(AddFunction("short LENS3GetFLcomp2( long* val )", (void*)JeolComDM::LENS3GetFLcomp2));
	fFunctionList.push_back(AddFunction("short DEF3SetGunA1( long x,  long y )", (void*)JeolComDM::DEF3SetGunA1));
	fFunctionList.push_back(AddFunction("short DEF3SetGunA2( long x, long y )", (void*)JeolComDM::DEF3SetGunA2));
	fFunctionList.push_back(AddFunction("short DEF3SetSpotA( long x, long y )", (void*)JeolComDM::DEF3SetSpotA));
	fFunctionList.push_back(AddFunction("short DEF3SetCLA1( long x,  long y )", (void*)JeolComDM::DEF3SetCLA1));
	fFunctionList.push_back(AddFunction("short DEF3SetCLA2( long x, long y )", (void*)JeolComDM::DEF3SetCLA2));
	fFunctionList.push_back(AddFunction("short DEF3SetCLs( long x,  long y )", (void*)JeolComDM::DEF3SetCLs));
	fFunctionList.push_back(AddFunction("short DEF3SetOLs( long x, long y )", (void*)JeolComDM::DEF3SetOLs));
	fFunctionList.push_back(AddFunction("short DEF3SetILs( long x,  long y )", (void*)JeolComDM::DEF3SetILs));
	fFunctionList.push_back(AddFunction("short DEF3SetIS1( long x,  long y )", (void*)JeolComDM::DEF3SetIS1));
	fFunctionList.push_back(AddFunction("short DEF3SetIS2( long x,  long y )", (void*)JeolComDM::DEF3SetIS2));
	fFunctionList.push_back(AddFunction("short DEF3SetFLA1( long x, long y )", (void*)JeolComDM::DEF3SetFLA1));
	fFunctionList.push_back(AddFunction("short DEF3SetFLA2( long x,  long y )", (void*)JeolComDM::DEF3SetFLA2));
	fFunctionList.push_back(AddFunction("short DEF3SetFLs1( long x, long y )", (void*)JeolComDM::DEF3SetFLs1));
	fFunctionList.push_back(AddFunction("short DEF3SetFLs2( long x, long y )", (void*)JeolComDM::DEF3SetFLs2));
	fFunctionList.push_back(AddFunction("short DEF3SetPLA( long x, long y )", (void*)JeolComDM::DEF3SetPLA));
	fFunctionList.push_back(AddFunction("short DEF3SetShifBal( long x,  long y )", (void*)JeolComDM::DEF3SetShifBal));
	fFunctionList.push_back(AddFunction("short DEF3SetTiltBal( long x,  long y )", (void*)JeolComDM::DEF3SetTiltBal));
	fFunctionList.push_back(AddFunction("short DEF3SetAngBal( long x,  long y )", (void*)JeolComDM::DEF3SetAngBal));
	fFunctionList.push_back(AddFunction("short DEF3SetDetAlign( short id, long x, long y )", (void*)JeolComDM::DEF3SetDetAlign));
	fFunctionList.push_back(AddFunction("short DEF3SetScan1( long x, long y )", (void*)JeolComDM::DEF3SetScan1));
	fFunctionList.push_back(AddFunction("short DEF3SetScan2( long x, long y )", (void*)JeolComDM::DEF3SetScan2));
	fFunctionList.push_back(AddFunction("short DEF3SetStemIS( long x, long y )", (void*)JeolComDM::DEF3SetStemIS));
	fFunctionList.push_back(AddFunction("short DEF3SetDefNtrl( short def )", (void*)JeolComDM::DEF3SetDefNtrl));
	fFunctionList.push_back(AddFunction("short DEF3GetGunA1( long* x, long* y )", (void*)JeolComDM::DEF3GetGunA1));
	fFunctionList.push_back(AddFunction("short DEF3GetGunA2( long* x, long* y )", (void*)JeolComDM::DEF3GetGunA2));
	fFunctionList.push_back(AddFunction("short DEF3GetSpotA( long* x, long* y )", (void*)JeolComDM::DEF3GetSpotA));
	fFunctionList.push_back(AddFunction("short DEF3GetCLA1( long* x, long* y )", (void*)JeolComDM::DEF3GetCLA1));
	fFunctionList.push_back(AddFunction("short DEF3GetCLA2( long* x, long* y )", (void*)JeolComDM::DEF3GetCLA2));
	fFunctionList.push_back(AddFunction("short DEF3GetCLs( long* x, long* y )", (void*)JeolComDM::DEF3GetCLs));
	fFunctionList.push_back(AddFunction("short DEF3GetOLs( long* x, long* y )", (void*)JeolComDM::DEF3GetOLs));
	fFunctionList.push_back(AddFunction("short DEF3GetILs( long* x, long* y )", (void*)JeolComDM::DEF3GetILs));
	fFunctionList.push_back(AddFunction("short DEF3GetIS1( long* x, long* y )", (void*)JeolComDM::DEF3GetIS1));
	fFunctionList.push_back(AddFunction("short DEF3GetIS2( long* x, long* y )", (void*)JeolComDM::DEF3GetIS2));
	fFunctionList.push_back(AddFunction("short DEF3GetFLA1( long* x, long* y )", (void*)JeolComDM::DEF3GetFLA1));
	fFunctionList.push_back(AddFunction("short DEF3GetFLA2( long* x, long* y )", (void*)JeolComDM::DEF3GetFLA2));
	fFunctionList.push_back(AddFunction("short DEF3GetFLs1( long* x, long* y )", (void*)JeolComDM::DEF3GetFLs1));
	fFunctionList.push_back(AddFunction("short DEF3GetFLs2( long* x, long* y )", (void*)JeolComDM::DEF3GetFLs2));
	fFunctionList.push_back(AddFunction("short DEF3GetPLA( long* x, long* y )", (void*)JeolComDM::DEF3GetPLA));
	fFunctionList.push_back(AddFunction("short DEF3GetDetAlign( short id, long* x, long* y )", (void*)JeolComDM::DEF3GetDetAlign));
	fFunctionList.push_back(AddFunction("short DEF3GetShifBal( long* x, long* y )", (void*)JeolComDM::DEF3GetShifBal));
	fFunctionList.push_back(AddFunction("short DEF3GetTiltBal( long* x, long* y )", (void*)JeolComDM::DEF3GetTiltBal));
	fFunctionList.push_back(AddFunction("short DEF3GetAngBal( long* x, long* y )", (void*)JeolComDM::DEF3GetAngBal));
	fFunctionList.push_back(AddFunction("short DEF3GetScan1( long* x, long* y )", (void*)JeolComDM::DEF3GetScan1));
	fFunctionList.push_back(AddFunction("short DEF3GetScan2( long* x, long* y )", (void*)JeolComDM::DEF3GetScan2));
	fFunctionList.push_back(AddFunction("short DEF3GetStemIS( long* x, long* y )", (void*)JeolComDM::DEF3GetStemIS));
	fFunctionList.push_back(AddFunction("short DEF3SetBeamBlank( short sw )", (void*)JeolComDM::DEF3SetBeamBlank));
	fFunctionList.push_back(AddFunction("short DEF3GetBeamBlank( short* sw )", (void*)JeolComDM::DEF3GetBeamBlank));
	fFunctionList.push_back(AddFunction("short EFILTER3SetEnergyShift( float val )", (void*)JeolComDM::EFILTER3SetEnergyShift));
	fFunctionList.push_back(AddFunction("short EFILTER3GetEnergyShift( float* val )", (void*)JeolComDM::EFILTER3GetEnergyShift));
	fFunctionList.push_back(AddFunction("short EFILTER3GetEnergyShiftRange( float* max, float* step )", (void*)JeolComDM::EFILTER3GetEnergyShiftRange));
	fFunctionList.push_back(AddFunction("short EFILTER3SetEnergyShiftSw( short sw )", (void*)JeolComDM::EFILTER3SetEnergyShiftSw));
	fFunctionList.push_back(AddFunction("short EFILTER3GetEnergyShiftSw( short* sw )", (void*)JeolComDM::EFILTER3GetEnergyShiftSw));
	fFunctionList.push_back(AddFunction("short EFILTER3SetSlitWidth( float width )", (void*)JeolComDM::EFILTER3SetSlitWidth));
	fFunctionList.push_back(AddFunction("short EFILTER3GetSlitWidth( float* width )", (void*)JeolComDM::EFILTER3GetSlitWidth));
	fFunctionList.push_back(AddFunction("short EFILTER3SetSlitPosotion( short inout )", (void*)JeolComDM::EFILTER3SetSlitPosotion));
	fFunctionList.push_back(AddFunction("short EFILTER3GetSlitPosition( short* pos )", (void*)JeolComDM::EFILTER3GetSlitPosition));
	fFunctionList.push_back(AddFunction("short EFILTER3GetSlitWidthRange( float* max, float* step )", (void*)JeolComDM::EFILTER3GetSlitWidthRange));
	fFunctionList.push_back(AddFunction("short STAGE3SetStagePosition( float x, float y )", (void*)JeolComDM::STAGE3SetStagePosition));
	fFunctionList.push_back(AddFunction("short STAGE3SetX( float x )", (void*)JeolComDM::STAGE3SetX));
	fFunctionList.push_back(AddFunction("short STAGE3SetY( float y )", (void*)JeolComDM::STAGE3SetY));
	fFunctionList.push_back(AddFunction("short STAGE3SetZ( float z )", (void*)JeolComDM::STAGE3SetZ));
	fFunctionList.push_back(AddFunction("short STAGE3SetTiltXAngle( float tiltx )", (void*)JeolComDM::STAGE3SetTiltXAngle));
	fFunctionList.push_back(AddFunction("short STAGE3SetTiltYAngle( float angle )", (void*)JeolComDM::STAGE3SetTiltYAngle));
	fFunctionList.push_back(AddFunction("short STAGE3SetXRel( float relx )", (void*)JeolComDM::STAGE3SetXRel));
	fFunctionList.push_back(AddFunction("short STAGE3SetYRel( float rely )", (void*)JeolComDM::STAGE3SetYRel));
	fFunctionList.push_back(AddFunction("short STAGE3SetZRel( float relz )", (void*)JeolComDM::STAGE3SetZRel));
	fFunctionList.push_back(AddFunction("short STAGE3SetTXRel( float reltx )", (void*)JeolComDM::STAGE3SetTXRel));
	fFunctionList.push_back(AddFunction("short STAGE3SetTYRel( float ty )", (void*)JeolComDM::STAGE3SetTYRel));
	fFunctionList.push_back(AddFunction("short STAGE3SetOrg()", (void*)JeolComDM::STAGE3SetOrg));
	fFunctionList.push_back(AddFunction("short STAGE3SelDrvMode( short sw )", (void*)JeolComDM::STAGE3SelDrvMode));
	fFunctionList.push_back(AddFunction("short STAGE3GetDrvMode( short* sw )", (void*)JeolComDM::STAGE3GetDrvMode));
	fFunctionList.push_back(AddFunction("short STAGE3Stop()", (void*)JeolComDM::STAGE3Stop));
	fFunctionList.push_back(AddFunction("short STAGE3GetPos( float* x, float* y, float* z, float* tx, float* ty )", (void*)JeolComDM::STAGE3GetPos));
	fFunctionList.push_back(AddFunction("short STAGE3GetStatus( short* x, short* y, short* z, short* tx, short* ty )", (void*)JeolComDM::STAGE3GetStatus));
	fFunctionList.push_back(AddFunction("short STAGE3GetDirection( short* x, short* y, short* z, short* tx, short* ty )", (void*)JeolComDM::STAGE3GetDirection));
	fFunctionList.push_back(AddFunction("short STAGE3GetPiezoPosi( float* x, float* y )", (void*)JeolComDM::STAGE3GetPiezoPosi));
	fFunctionList.push_back(AddFunction("short STAGE3GetHolderStts( short* stts )", (void*)JeolComDM::STAGE3GetHolderStts));
	fFunctionList.push_back(AddFunction("short DETECTOR3SetScreen( short sw )", (void*)JeolComDM::DETECTOR3SetScreen));
	fFunctionList.push_back(AddFunction("short DETECTOR3SetPosition( short code, short position )", (void*)JeolComDM::DETECTOR3SetPosition));
	fFunctionList.push_back(AddFunction("short DETECTOR3GetPosition( short code, short* position )", (void*)JeolComDM::DETECTOR3GetPosition));
	fFunctionList.push_back(AddFunction("short DETECTOR3SetImageSw( short code, short sw )", (void*)JeolComDM::DETECTOR3SetImageSw));
	fFunctionList.push_back(AddFunction("short DETECTOR3GetImageSw( short code, short* sw )", (void*)JeolComDM::DETECTOR3GetImageSw));
	fFunctionList.push_back(AddFunction("short DETECTOR3SetBrt( short code, short val )", (void*)JeolComDM::DETECTOR3SetBrt));
	fFunctionList.push_back(AddFunction("short DETECTOR3GetBrt( short code, short* val )", (void*)JeolComDM::DETECTOR3GetBrt));
	fFunctionList.push_back(AddFunction("short DETECTOR3SetCont( short code, short val )", (void*)JeolComDM::DETECTOR3SetCont));
	fFunctionList.push_back(AddFunction("short DETECTOR3GetCont( short code, short* val )", (void*)JeolComDM::DETECTOR3GetCont));
	fFunctionList.push_back(AddFunction("short APT3GetKind( short* id )", (void*)JeolComDM::APT3GetKind));
	fFunctionList.push_back(AddFunction("short APT3SelectKind( short id )", (void*)JeolComDM::APT3SelectKind));
	fFunctionList.push_back(AddFunction("short APT3GetPosition( short* x, short* y )", (void*)JeolComDM::APT3GetPosition));
	fFunctionList.push_back(AddFunction("short APT3SetPosition( short x, short y )", (void*)JeolComDM::APT3SetPosition));
	fFunctionList.push_back(AddFunction("short APT3GetSize( short kind, short* num )", (void*)JeolComDM::APT3GetSize));
	fFunctionList.push_back(AddFunction("short APT3SetSize( short num )", (void*)JeolComDM::APT3SetSize));
	fFunctionList.push_back(AddFunction("short SCAN3SetExtScanMode( short sw )", (void*)JeolComDM::SCAN3SetExtScanMode));
	fFunctionList.push_back(AddFunction("short SCAN3GetExtScanMode( short* sw )", (void*)JeolComDM::SCAN3GetExtScanMode));
	fFunctionList.push_back(AddFunction("short SCAN3GetRotationAngle( short* angle )", (void*)JeolComDM::SCAN3GetRotationAngle));
	fFunctionList.push_back(AddFunction("short SCAN3SetRotationAngle( short angle )", (void*)JeolComDM::SCAN3SetRotationAngle));
	fFunctionList.push_back(AddFunction("short CAMERA3SetExpTime( float time )", (void*)JeolComDM::CAMERA3SetExpTime));
	fFunctionList.push_back(AddFunction("short CAMERA3GetExpTime( float* time )", (void*)JeolComDM::CAMERA3GetExpTime));
	fFunctionList.push_back(AddFunction("short CAMERA3SelectFilmLoadingMode( short film_feed )", (void*)JeolComDM::CAMERA3SelectFilmLoadingMode));
	fFunctionList.push_back(AddFunction("short CAMERA3TakePhoto()", (void*)JeolComDM::CAMERA3TakePhoto));
	fFunctionList.push_back(AddFunction("short CAMERA3CancelPhoto()", (void*)JeolComDM::CAMERA3CancelPhoto));
	fFunctionList.push_back(AddFunction("short CAMERA3GetStatus( short* stts )", (void*)JeolComDM::CAMERA3GetStatus));
	fFunctionList.push_back(AddFunction("short CAMERA3SelectMode( short shutter_mode )", (void*)JeolComDM::CAMERA3SelectMode));
	fFunctionList.push_back(AddFunction("short CAMERA3GetMode( short* shutter_mode )", (void*)JeolComDM::CAMERA3GetMode));
	fFunctionList.push_back(AddFunction("short CAMERA3GetCurrentDensity( float* value )", (void*)JeolComDM::CAMERA3GetCurrentDensity));
	fFunctionList.push_back(AddFunction("short CAMERA3SetShutterPosition( short sw )", (void*)JeolComDM::CAMERA3SetShutterPosition));
	fFunctionList.push_back(AddFunction("short CAMERA3GetShutterPosition( short* sw )", (void*)JeolComDM::CAMERA3GetShutterPosition));
	fFunctionList.push_back(AddFunction("short CAMERA3ExposeShutter( float time )", (void*)JeolComDM::CAMERA3ExposeShutter));
	fFunctionList.push_back(AddFunction("short MDS3SetSearchMode()", (void*)JeolComDM::MDS3SetSearchMode));
	fFunctionList.push_back(AddFunction("short MDS3SetFocusMode()", (void*)JeolComDM::MDS3SetFocusMode));
	fFunctionList.push_back(AddFunction("short MDS3SetPhotosetMode()", (void*)JeolComDM::MDS3SetPhotosetMode));
	fFunctionList.push_back(AddFunction("short MDS3EndMdsMode()", (void*)JeolComDM::MDS3EndMdsMode));
	fFunctionList.push_back(AddFunction("short MDS3GetMdsMode( short* mode )", (void*)JeolComDM::MDS3GetMdsMode));
	fFunctionList.push_back(AddFunction("short SCREEN1SetAngle( short sw )", (void*)JeolComDM::SCREEN1SetAngle));
	fFunctionList.push_back(AddFunction("short SCREEN1GetAngle( short* sw )", (void*)JeolComDM::SCREEN1GetAngle));

	//CreateCOMInterface();

}

void JeolComPlugIn::Run()
{
	DM::Result("Run Jeol Plugin...\n");
	JeolComDM::Connect();

}

void JeolComPlugIn::Cleanup()
{
	DM::Result("Cleanup Jeol Plugin...\n");
	FunctionList::const_iterator functionPtr;

	for (functionPtr = fFunctionList.begin();
		functionPtr != fFunctionList.end();
		++functionPtr)
	{
		RemoveFunction(*functionPtr);
	}
	//DM::Beep();
	//DMPlugInCOMUtility.DllUnregisterServer();
	//DM::Beep();
}

void JeolComPlugIn::End()
{
	DM::Result("End Jeol Plugin...\n");
	//JeolComDM::Disconnect();
	//DestroyCOMInterface();
}

JeolComPlugIn  gJeolComPlugIn;
