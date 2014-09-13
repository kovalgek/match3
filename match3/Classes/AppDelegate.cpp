#include "AppDelegate.h"
#include "GameScene.h"

USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
}

typedef struct tagResource
{
    Size size;
    char directory[100];
} Resource;

//static Resource smallerResource  =  { Size(640, 1136),  "iPhone5"  };
static Resource smallResource  =  { Size(640, 1136),  "iPhone5"  };
static Resource mediumResource =  { Size(1080, 1920), "iPhone6+" };
static Resource largeResource  =  { Size(1536, 2048), "iPad3"    };

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview)
    {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }

    director->setDisplayStats(true);
    director->setAnimationInterval(1.0 / 60);
    
    std::vector<std::string> searchPaths;
    
    Size screenSize = glview->getFrameSize();
    Size designResolutionSize = Size(640, 1136);
    
    std::vector<std::string> paths;
    
    
    if (screenSize.height > mediumResource.size.height)
    {
        paths.push_back(largeResource.directory);
        director->setContentScaleFactor(largeResource.size.width/designResolutionSize.width);
    }
    else if (screenSize.height > smallResource.size.height)
    {
        paths.push_back(mediumResource.directory);
        director->setContentScaleFactor(mediumResource.size.width/designResolutionSize.width);
    }
    else
    {
        paths.push_back(smallResource.directory);
        director->setContentScaleFactor(smallResource.size.width/designResolutionSize.width);
    }
    
    FileUtils::getInstance()->setSearchPaths(paths);
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
    
    auto scene = GameScene::createScene();

    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
