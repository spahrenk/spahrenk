#ifndef _JEOLCOMPLUGIN_
#define _JEOLCOMPLUGIN_

#ifndef _JEOLCOMDM_
#include "JeolComDM.h"
#endif


using namespace Gatan;

class JeolComPlugIn:public GatanPlugIn::PlugInMain
{	
private:
//	bool fIsCOMInitialized;
//	bool fIsModuleInitialized;
//	bool fAreClassesRegistered;

//	void CreateCOMInterface();
//	void DestroyCOMInterface();

protected:
	virtual void Start();
	virtual void Run();
	virtual void Cleanup();
	virtual void End();

	typedef std::vector<DM::Function> FunctionList;
	typedef FunctionList::iterator functionPtr;
	FunctionList fFunctionList;
	//JeolComDM tem;

public:
	JeolComPlugIn();
	~JeolComPlugIn();

};

#endif