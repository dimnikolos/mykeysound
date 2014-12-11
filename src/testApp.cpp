#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    myfont.loadFont("arial.ttf", 32);
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
    //BASIC KEYBOARD
    //QWERTYUIOP
    ofSetColor(0,0,0);
    for (int i=0; i<10; i++)
    {
        if (soundPlayerArray[i].getIsPlaying())
            ofSetHexColor(0xFF0000);
        ofRect(20+(WIDTH+10)*i,30,WIDTH,WIDTH);
        ofSetHexColor(0xFFFFFF);
        std::string keyString(1,keyArray[i]);
        myfont.drawString(keyString,40+(WIDTH+10)*i,30+WIDTH-20);
        ofSetHexColor(0x000000);
    }
    //ASDFGHJKL
    for (int i=0; i<9; i++)
    {
        if (soundPlayerArray[i+10].getIsPlaying())
            ofSetHexColor(0xFF0000);
        ofRect(40+(WIDTH+10)*i,WIDTH+40,WIDTH,WIDTH);
        ofSetHexColor(0xFFFFFF);
        std::string keyString(1,keyArray[i+10]);
        myfont.drawString(keyString,60+(WIDTH+10)*i,2*WIDTH+20);
        ofSetHexColor(0x000000);
    }
    //ZXCVBNM
    for (int i=0; i<7; i++)
    {
        if (soundPlayerArray[i+19].getIsPlaying())
            ofSetHexColor(0xFF0000);
        ofRect(60+(WIDTH+10)*i, 2*WIDTH+50, WIDTH, WIDTH);
        ofSetHexColor(0xFFFFFF);
        std::string keyString(1,keyArray[i+19]);
        myfont.drawString(keyString,80+(WIDTH+10)*i, 3*WIDTH+30);
        ofSetHexColor(0x000000);
    }

    //ARROW KEYS
    for (int i=0; i<3; i++)
    {
        if (soundPlayerArray[i+26].getIsPlaying())
            ofSetHexColor(0xFF0000);
        ofRect(60+(WIDTH+10)*(8+i), 3*WIDTH+50, WIDTH, WIDTH);
        ofSetHexColor(0x000000);
    }
    if (soundPlayerArray[29].getIsPlaying())
            ofSetHexColor(0xFF0000);
    ofRect(60+(WIDTH+10)*9,2*WIDTH+40, WIDTH, WIDTH);
    ofSetHexColor(0x000000);
    //SPACE
     if (soundPlayerArray[30].getIsPlaying())
            ofSetHexColor(0xFF0000);
    ofRect(60+(WIDTH+10)*2,3*WIDTH+60, WIDTH*5, WIDTH);
    ofSetHexColor(0x000000);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
int keynum = -1;
for (int i=0; i<26; i++)
    if (key == keyArray[i] || key == tolower(keyArray[i]))
    {
        keynum = i;
        break;
    }
    if (key == OF_KEY_LEFT)
        keynum = 26;
    if (key == OF_KEY_DOWN)
        keynum = 27;
    if (key == OF_KEY_RIGHT)
        keynum = 28;
    if (key == OF_KEY_UP)
        keynum = 29;
    if (key == ' ')
        keynum = 30;
    if (keynum!=-1)
    {
        if (soundPlayerArray[keynum].isLoaded())
        {
            soundPlayerArray[keynum].setLoop(true);
            if (soundPlayerArray[keynum].getIsPlaying())
                soundPlayerArray[keynum].stop();
            else
                soundPlayerArray[keynum].play();
        }

    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
if (!button)
    {
    int keynum=-1;
    for (int i=0; i<10; i++)
        if (x > 20+(WIDTH+10)*i &&
            x < 20+(WIDTH+10)*i+WIDTH &&
            y > 30 &&
            y < 30+WIDTH)
        {
            keynum =i;
            break;
        }

    //ASDFGHJKL
    for (int i=0; i<9; i++)
        if (x > 40+(WIDTH+10)*i &&
            x < 40+(WIDTH+10)*i + WIDTH &&
            y > WIDTH+40 &&
            y < WIDTH+40+WIDTH)
        {
            keynum =10+i;
            break;
        }

    //ZXCVBNM
    for (int i=0; i<7; i++)
        if (x > 60+(WIDTH+10)*i &&
            x < 60+(WIDTH+10)*i + WIDTH &&
            y > 2*WIDTH+50 &&
            y < 2*WIDTH+50 + WIDTH)
        {
            keynum =19+i;
            break;
        }

    //ARROW KEYS
    for (int i=0; i<3; i++)
        if (x > 60+(WIDTH+10)*(8+i) &&
            x < 60+(WIDTH+10)*(8+i)+WIDTH &&
            y > 3*WIDTH+50 &&
            y < 3*WIDTH+50+WIDTH)
        {
            keynum =26+i;
            break;
        }
    if (x>60+(WIDTH+10)*9 &&
        x<60+(WIDTH+10)*9+WIDTH &&
        y>2*WIDTH+40 &&
        y<2*WIDTH+40 +WIDTH)
        {
            keynum = 29;
        }

    //SPACE
    if (x>60+(WIDTH+10)*2 &&
        x<60+(WIDTH+10)*2+5*WIDTH &&
        y>3*WIDTH+60 &&
        y<3*WIDTH+60+WIDTH)
        {
            keynum =30;
        }
    if (keynum!=-1)
    {
        ofFileDialogResult dialogResult = ofSystemLoadDialog("Load Sound");
        if (dialogResult.bSuccess)
            {
            soundPlayerArray[keynum].loadSound(dialogResult.getPath());
            if (soundPlayerArray[keynum].isLoaded())
                soundPlayerArray[keynum].setLoop(false);
                soundPlayerArray[keynum].play();
            }
    }
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
