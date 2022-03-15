#ifndef _JEOLCOMDM_
#define _JEOLCOMDM_

#ifndef _JEOLCOM_
#include "JeolCom.h"
#endif

#include <cstdlib>
#include <iostream>

#include "stdafxDM.h"

class JeolComDM
{

public:

	//JeolCom tem;
	//JeolComDM();

	//JeolCom( JeolCom const& );
	//JeolCom& operator=( JeolCom const& );

	static void Connect();
	static void Disconnect();
	static short HT3SetHtValue(float val);
	static short HT3GetHtValue(float* val);
	static short HT3GetHtRange(float* maxValue, float* minStep);
	static short GUN3SetFilamentVal(float val);
	static short GUN3GetFilamentVal(float* val);
	static short GUN3GetHtStts(short* sw);
	static short GUN3SetBeamSw(short sw);
	static short GUN3GetBeamSw(short* sw);
	static short FEG3SetBeamValve(short sw);
	static short FEG3GetBeamValve(short* sw);
	static short EOS3SelectTemStem(short mode);
	static short EOS3GetTemStemMode(short* mode);
	static short EOS3SelectSpotSize(short size);
	static short EOS3GetSpotSize(short* size);
	static short EOS3SelectProbMode(short mode);
	static short EOS3GetProbeMode(short* mode, DM_StringToken* name);
	static short EOS3SetAlphaSelector(short sel);
	static short EOS3GetAlpha(short* alpha);
	static short EOS3SelectFunctionMode(short mode);
	static short EOS3GetFunctionMode(short* mode, DM_StringToken* name);
	static short EOS3SetSelector(short sel);
	static short EOS3UpSelector();
	static short EOS3DownSelector();
	static short EOS3GetMagValue(long* mag, DM_StringToken* unit, DM_StringToken* string);
	static short EOS3SetMagValue(long magValue);
	static short EOS3SetSpctrMode(short mode);
	static short EOS3GetSpctrMode(short* mode);
	static short EOS3SetSpctrSelector(short sel);
	static short EOS3UpSpctrSelector();
	static short EOS3DownSpctrSelector();
	static short EOS3GetSpctrValue(long* dispersion, DM_StringToken* unit, DM_StringToken* string);
	static short EOS3SetStemCamSelector(short sel);
	static short EOS3UpStemCamSelector();
	static short EOS3DownStemCamSelector();
	static short EOS3GetStemCamValue(long* cam, DM_StringToken* unit, DM_StringToken* string);
	static short EOS3SetBrightness(short relval);
	static short EOS3SetObjFocus(short relval);
	static short EOS3SetDiffFocus(short relval);
	static short LENS3SetCL3(long val);
	static short LENS3SetOLf(long val);
	static short LENS3SetOLc(long val);
	static short LENS3SetOM(long val);
	static short LENS3SetDiffFocus(long val);
	static short LENS3SetILFocus(long val);
	static short LENS3SetPLFocus(long val);
	static short LENS3SetFLf(long val);
	static short LENS3SetFLc(long val);
	static short LENS3SetNtrl(short lens);
	static short LENS3GetCL1(long* val);
	static short LENS3GetCL2(long* val);
	static short LENS3GetCL3(long* val);
	static short LENS3GetCM(long* val);
	static short LENS3GetOLf(long* val);
	static short LENS3GetOLc(long* val);
	static short LENS3GetOM(long* val);
	static short LENS3GetOM2(long* val);
	static short LENS3GetOM2Flag(short* flag);
	static short LENS3GetIL1(long* val);
	static short LENS3GetIL2(long* val);
	static short LENS3GetIL3(long* val);
	static short LENS3GetIL4(long* val);
	static short LENS3GetPL1(long* val);
	static short LENS3GetPL2(long* val);
	static short LENS3GetPL3(long* val);
	static short LENS3GetFLf(long* val);
	static short LENS3GetFLc(long* val);
	static short LENS3GetFLcomp1(long* val);
	static short LENS3GetFLcomp2(long* val);
	static short DEF3SetGunA1(long x, long y);
	static short DEF3SetGunA2(long x, long y);
	static short DEF3SetSpotA(long x, long y);
	static short DEF3SetCLA1(long x, long y);
	static short DEF3SetCLA2(long x, long y);
	static short DEF3SetCLs(long x, long y);
	static short DEF3SetOLs(long x, long y);
	static short DEF3SetILs(long x, long y);
	static short DEF3SetIS1(long x, long y);
	static short DEF3SetIS2(long x, long y);
	static short DEF3SetFLA1(long x, long y);
	static short DEF3SetFLA2(long x, long y);
	static short DEF3SetFLs1(long x, long y);
	static short DEF3SetFLs2(long x, long y);
	static short DEF3SetPLA(long x, long y);
	static short DEF3SetShifBal(long x, long y);
	static short DEF3SetTiltBal(long x, long y);
	static short DEF3SetAngBal(long x, long y);
	static short DEF3SetDetAlign(short id, long x, long y);
	static short DEF3SetScan1(long x, long y);
	static short DEF3SetScan2(long x, long y);
	static short DEF3SetStemIS(long x, long y);
	static short DEF3SetDefNtrl(short def);
	static short DEF3GetGunA1(long* x, long* y);
	static short DEF3GetGunA2(long* x, long* y);
	static short DEF3GetSpotA(long* x, long* y);
	static short DEF3GetCLA1(long* x, long* y);
	static short DEF3GetCLA2(long* x, long* y);
	static short DEF3GetCLs(long* x, long* y);
	static short DEF3GetOLs(long* x, long* y);
	static short DEF3GetILs(long* x, long* y);
	static short DEF3GetIS1(long* x, long* y);
	static short DEF3GetIS2(long* x, long* y);
	static short DEF3GetFLA1(long* x, long* y);
	static short DEF3GetFLA2(long* x, long* y);
	static short DEF3GetFLs1(long* x, long* y);
	static short DEF3GetFLs2(long* x, long* y);
	static short DEF3GetPLA(long* x, long* y);
	static short DEF3GetDetAlign(short id, long* x, long* y);
	static short DEF3GetShifBal(long* x, long* y);
	static short DEF3GetTiltBal(long* x, long* y);
	static short DEF3GetAngBal(long* x, long* y);
	static short DEF3GetScan1(long* x, long* y);
	static short DEF3GetScan2(long* x, long* y);
	static short DEF3GetStemIS(long* x, long* y);
	static short DEF3SetBeamBlank(short sw);
	static short DEF3GetBeamBlank(short* sw);
	static short EFILTER3SetEnergyShift(float val);
	static short EFILTER3GetEnergyShift(float* val);
	static short EFILTER3GetEnergyShiftRange(float* max, float* step);
	static short EFILTER3SetEnergyShiftSw(short sw);
	static short EFILTER3GetEnergyShiftSw(short* sw);
	static short EFILTER3SetSlitWidth(float width);
	static short EFILTER3GetSlitWidth(float* width);
	static short EFILTER3SetSlitPosotion(short inout);
	static short EFILTER3GetSlitPosition(short* pos);
	static short EFILTER3GetSlitWidthRange(float* max, float* step);
	static short STAGE3SetStagePosition(float x, float y);
	static short STAGE3SetX(float x);
	static short STAGE3SetY(float y);
	static short STAGE3SetZ(float z);
	static short STAGE3SetTiltXAngle(float tiltx);
	static short STAGE3SetTiltYAngle(float angle);
	static short STAGE3SetXRel(float relx);
	static short STAGE3SetYRel(float rely);
	static short STAGE3SetZRel(float relz);
	static short STAGE3SetTXRel(float reltx);
	static short STAGE3SetTYRel(float ty);
	static short STAGE3SetOrg();
	static short STAGE3SelDrvMode(short sw);
	static short STAGE3GetDrvMode(short* sw);
	static short STAGE3Stop();
	static short STAGE3GetPos(float* x, float* y, float* z, float* tx, float* ty);
	static short STAGE3GetStatus(short* x, short* y, short* z, short* tx, short* ty);
	static short STAGE3GetDirection(short* x, short* y, short* z, short* tx, short* ty);
	static short STAGE3GetPiezoPosi(float* x, float* y);
	static short STAGE3GetHolderStts(short* stts);
	static short DETECTOR3SetScreen(short sw);
	static short DETECTOR3SetPosition(short code, short position);
	static short DETECTOR3GetPosition(short code, short* position);
	static short DETECTOR3SetImageSw(short code, short sw);
	static short DETECTOR3GetImageSw(short code, short* sw);
	static short DETECTOR3SetBrt(short code, short val);
	static short DETECTOR3GetBrt(short code, short* val);
	static short DETECTOR3SetCont(short code, short val);
	static short DETECTOR3GetCont(short code, short* val);
	static short APT3GetKind(short* id);
	static short APT3SelectKind(short id);
	static short APT3GetPosition(short* x, short* y);
	static short APT3SetPosition(short x, short y);
	static short APT3GetSize(short kind, short* num);
	static short APT3SetSize(short num);
	static short SCAN3SetExtScanMode(short sw);
	static short SCAN3GetExtScanMode(short* sw);
	static short SCAN3GetRotationAngle(short* angle);
	static short SCAN3SetRotationAngle(short angle);
	static short CAMERA3SetExpTime(float time);
	static short CAMERA3GetExpTime(float* time);
	static short CAMERA3SelectFilmLoadingMode(short film_feed);
	static short CAMERA3TakePhoto();
	static short CAMERA3CancelPhoto();
	static short CAMERA3GetStatus(short* stts);
	static short CAMERA3SelectMode(short shutter_mode);
	static short CAMERA3GetMode(short* shutter_mode);
	static short CAMERA3GetCurrentDensity(float* value);
	static short CAMERA3SetShutterPosition(short sw);
	static short CAMERA3GetShutterPosition(short* sw);
	static short CAMERA3ExposeShutter(float time);
	static short MDS3SetSearchMode();
	static short MDS3SetFocusMode();
	static short MDS3SetPhotosetMode();
	static short MDS3EndMdsMode();
	static short MDS3GetMdsMode(short* mode);
	short TEM3CheckEnabled();
	short TEM3SetRecvTimeout(long timer);
	static short SCREEN1SetAngle(short sw);
	static short SCREEN1GetAngle(short *sw);

};


#endif

