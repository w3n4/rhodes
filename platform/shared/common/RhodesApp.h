#pragma once

#ifdef __cplusplus

#include "logging/RhoLog.h"
#include "common/RhoThread.h"
#include "common/IRhoBrowser.h"

struct shttpd_ctx;

namespace rho {
namespace common {

class CRhodesApp : public common::CRhoThread
{
    DEFINE_LOGCLASS;
    static CRhodesApp* m_pInstance;
    CRhodesApp(const String& strRootPath, IRhoBrowser* pRhoBrowser);
    boolean m_bExit;

    String m_strListeningPorts;
    struct shttpd_ctx * m_shttpdCtx;
    String m_strRhoRootPath;
    String m_strHomeUrl, m_strStartUrl, m_strOptionsUrl, m_strRhobundleReloadUrl;
    StringW m_strStartUrlW, m_strOptionsUrlW;

    common::CAutoPtr<common::IRhoBrowser> m_ptrRhoBrowser;

    void initHttpServer();
    void initAppUrls();
    String getFirstStartUrl();

public:
    ~CRhodesApp(void);

    static CRhodesApp* Create(const String& strRootPath, IRhoBrowser* pRhoBrowser);
    static void Destroy();
    static CRhodesApp* getInstance(){ return m_pInstance; }
    void exitApp();

	virtual void run();

    const char* getFreeListeningPort();
    const String& getRhoRootPath();
    String getSystemRootPath();
    const char* getRelativeBlobsPath(); 
    const wchar_t* getRelativeBlobsPathW();
    String getLoadingPagePath();
    String canonicalizeRhoUrl(const String& strUrl) ;
    const String& getRhobundleReloadUrl();
    const String& getStartUrl();
    const StringW& getStartUrlW();
    const StringW& getOptionsUrlW();
    void  keepLastVisitedUrl(String strUrl);

    void navigateToUrl( const String& strUrl);
};

}
}

inline rho::common::CRhodesApp& RHODESAPP(){ return *rho::common::CRhodesApp::getInstance(); }

#endif //__cplusplus

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus
	
void rho_rhodesapp_create(const char* szRootPath);
void rho_rhodesapp_destroy();
	
#ifdef __cplusplus
};
#endif //__cplusplus