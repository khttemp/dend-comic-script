// このソフトは？
// 電車でD 各シリーズのコミックスクリプトを解析するツールである。
// 使用法について地主一派への問い合わせを行わない事。
// その他の使用方法については、添付の ReadMe.md を参照すること。
//
// コンパイル方法
// > g++ script.cpp -o script -static-libgcc -static-libstdc++
// > cl.exe /MT script.cpp /Fe:script.exe
// > icl.exe /MT /O2 script.cpp /Fe:script.exe

// ヘッダー定義
#include <iostream>
#include <cstdlib> // for system() function
#include <fstream>
#include <cstring>
#include <string>
#include <Windows.h>

// プリプロセッサ定義
#define CMD_MAX 574
#define _MYDEBUG ( 0 )

// 使用する名前空間定義
using namespace std; // stdネーム空間を使用する

// グローバル変数定義ゾーン

int main( int argc , char **argv ) {

    // コミックスクリプトのコマンド定義一覧、以下600行程度存在する。
    string cmd[CMD_MAX] = {
        "Tx",
        "TxSize",
        "Alpha",
        "End",
        "Pos",
        "ColorALL",
        "Move",
        "STAGE_BGM",
        "SetFlat3D",
        "ChangeFlat3D",
        "SetCamDir",
        "DisCamDir",
        "Set3DObj",
        "SetWAngleX",
        "SetWAngleY",
        "SetWAngleZ",
        "SetLAngleX",
        "SetLAngleY",
        "SetLAngleZ",
        "SetBoneWAngleX",
        "SetBoneWAngleY",
        "SetBoneWAngleZ",
        "SetBoneLAngleX",
        "SetBoneLAngleY",
        "SetBoneLAngleZ",
        "ShowMesh",
        "HideMesh",
        "PlayAnime",
        "Length_End",
        "SetScall",
        "RACE_START",
        "RACE_END",
        "FADE_STAGE_BGM",
        "CHANGE_SCENE",
        "LPos",
        "LMove",
        "LLoopX",
        "LLoopY",
        "LLoopZ",
        "Angle",
        "AngleLoop",
        "Move2",
        "PosX",
        "PosY",
        "PosZ",
        "PlaySE",
        "SET_MT_NONE",
        "SetCamPos",
        "SetCamTarget",
        "CamMoveWait",
        "SetComic",
        "ComicPos",
        "ComicAlpha",
        "ComicWait",
        "Scene_to_Comic",
        "SKY_DOME",
        "Fill_BG",
        "ComicEnd",
        "CamComtroll",
        "ComicSceneStop",
        "BtnWait",
        "EyeMove",
        "SetZoom",
        "BG_Alpha",
        "BG_Wait",
        "StartCount",
        "WaitMoveEye",
        "WaitFrame",
        "FTV_Play",
        "FTV_Wait",
        "HideMsgWnd",
        "FTV_End",
        "SkipEventPoint",
        "SkipEventFlg",
        "PlayComicSE",
        "StopComicSE",
        "PlayComicBGM",
        "StopComicBGM",
        "VolComicBGM",
        "HideALLComic",
        "Stage_BGM_Vol",
        "SET_CPU_FLG",
        "SET_CPU_MODE",
        "CHK_LENGTH",
        "END_CHK_LENGTH",
        "CHK_POSTION",
        "END_CHK_POSTION",
        "WAIT_MOTION",
        "END_WAIT_MOTION",
        "CHANGE_SPEED",
        "CHANGE_CAM_TYPE",
        "Set2P",
        "CharChk_and_Tx",
        "ChangeR",
        "ChangeG",
        "ChangeB",
        "ChangeColor",
        "SetGray",
        "MoveX",
        "MoveY",
        "MoveZ",
        "SetUV_X",
        "RePlay",
        "IsStart",
        "ShowGoal",
        "CHK_WIN_TRAIN",
        "END_CHK_WINTRAIN",
        "N_ADD_OBJ",
        "N_POS",
        "START_TIME_LINE",
        "N_MOVE",
        "WAIT_TIME_LINE",
        "N_DEL_OBJ",
        "SCREEN_FADE",
        "N_CHANGE_ANIME",
        "TRAIN_SPEED",
        "TRAIN_FLG",
        "SCENE_LIGHT",
        "CHANGE_CAM_LENGTH",
        "CHANGE_CAM_DIRX",
        "CHANGE_CAM_DIRY",
        "CHANGE_CAM_DIRZ",
        "R_Drift",
        "L_Drift",
        "IS_TRAIN_HIT",
        "TO_RAIL",
        "SLEEP_TRAIN",
        "RandWAngle",
        "RandMove",
        "ADD_OBJ",
        "START_COMIC",
        "SetRand3DObj",
        "Offset3DObj",
        "RandPos",
        "RandPlaySE",
        "RandAngleX",
        "RandAngleY",
        "RandAngleZ",
        "CHK_TRAIN_STATE",
        "END_CHK_TRAIN_STATE",
        "CHK_TRAIN_SPEED_U",
        "CHK_TRAIN_SPEED_D",
        "END_CHK_TRAIN_SPEED_U",
        "END_CHK_TRAIN_SPEED_D",
        "ChkStory_and_Tx",
        "ClearStory_and_Tx",
        "N_L_ANGLE_X",
        "N_L_ANGLE_Y",
        "N_L_ANGLE_Z",
        "Comic_Glay",
        "N_MoveMesh_X",
        "N_MoveMesh_Y",
        "N_MoveMesh_Z",
        "SetComic_Blur",
        "SetComic_Blur_Speed",
        "TRACK_BOMB",
        "Hide_Sky_Doom",
        "ADD_POINT",
        "CHK_POINT",
        "ELSE_CHK_POINT",
        "ELSE_IF_CHK_POINT",
        "END_CHK_POINT",
        "GOTO_SCRIPT",
        "SHEAK_COMIC",
        "STORY_OPEN",
        "STORY_CLEAR",
        "CHAR_OPEN",
        "SAVE_GAME",
        "KEISUKE_COUNT",
        "RandPlayComicSE",
        "TITLE_MODE",
        "GOING",
        "RAND_IF",
        "ELSE_RAND_IF",
        "END_RAND_IF",
        "CHK_SP_BREAK",
        "END_CHK_SP_BREAK",
        "CHK_DRIFT",
        "END_CHK_DRIFT",
        "ENDING_MODE",
        "ChkCause_and_Tx",
        "SET_DRAW_TYPE",
        "To_TxSize",
        "OPEN_CAUSE",
        "DIS_TRAIN_SPEED",
        "CHK_RACE_TIME",
        "END_CHK_RACE_TIME",
        "End_Comic",
        "WAIT_RAIL",
        "END_WAIT_RAIL",
        "COMIC_SCALE",
        "USO_COUNT",
        "WaitRandPlaySE",
        "FROM",
        "GOTO",
        "CHK_TRAIN_TYPE",
        "RAND_IF_AVG",
        "CHK_NOTCH",
        "WAIT_RAIL_ONLY",
        "ONE_TRACK_DRIFT",
        "LAST_STATION",
        "OSSAN",
        "SET_TAIL_SCALE",
        "OPEN_HUTA",
        "SET_GN",
        "MDL_GETINDEX",
        "INDEX_BONE_ROT_X",
        "INDEX_BONE_ROT_Y",
        "INDEX_BONE_ROT_Z",
        "INDEX_BONE_L_ROT_X",
        "INDEX_BONE_L_ROT_Y",
        "INDEX_BONE_L_ROT_Z",
        "CREATE_INDEX",
        "IB_LI_CREATE_ROT_X",
        "IB_LI_CREATE_ROT_Y",
        "IB_LI_CREATE_ROT_Z",
        "IB_LI_SET_ROT_X",
        "IB_LI_SET_ROT_Y",
        "IB_LI_SET_ROT_Z",
        "IB_LI_SET_LOOP_X",
        "IB_LI_SET_LOOP_Y",
        "IB_LI_SET_LOOP_Z",
        "ADD_MY_OBJ",
        "INDEX_BONE_L_POS_X",
        "INDEX_BONE_L_POS_Y",
        "INDEX_BONE_L_POS_Z",
        "IB_LI_CREATE_L_POS_X",
        "IB_LI_CREATE_L_POS_Y",
        "IB_LI_CREATE_L_POS_Z",
        "IB_LI_SET_L_POS_X",
        "IB_LI_SET_L_POS_Y",
        "IB_LI_SET_L_POS_Z",
        "FROM_ADDMT",
        "MOVE_UV_X",
        "MOVE_UV_Y",
        "CREATE_UV_MOVE_X",
        "IB_LI_SET_LOOP_LPOSX",
        "IB_LI_SET_LOOP_LPOSY",
        "IB_LI_SET_LOOP_LPOSZ",
        "RELEASE_ALL_IB_LIST",
        "ADD_MY_OBJ_INDEX",
        "TO_TAGET_POS",
        "ATK_HIT",
        "ATK_END",
        "SET_RELEASE_PARAM",
        "CREATE_LENSFLEAR",
        "SET_LENSFLEAR_PARAM",
        "SET_LENSFLEAR_MT",
        "RAIL_POS_TO_BUFF",
        "BUFF_TO_CAM_POS",
        "BUFF_TO_TARGET_POS",
        "FTV_BASE_PROC",
        "FTV_NEXT_PROC",
        "MDL_INDEX_TO_VIEW",
        "SET_FOG_LENGTH",
        "SET_UV_MOVE_X",
        "SET_UV_LOOP_X",
        "CREATE_MESH_INDEX",
        "SET_MESH_INDEX",
        "INDEX_BONE_L_ADD_ROT_X",
        "INDEX_BONE_L_ADD_ROT_Y",
        "INDEX_BONE_L_ADD_ROT_Z",
        "CHANGE_SCALL",
        "CHK_CLEAR_STORY",
        "CHK_OPEN_STORY",
        "SET_LENSFLEAR_ALL_FLG",
        "CHK_USE_CHAR",
        "SET_OBJ_FOG_NO",
        "SET_OBJ_RENDER_ID",
        "PLAY_STAGE_BGM",
        "CHANGE_TRAIN_FOG",
        "FIRST_OBJ_SET_ANIME",
        "SET_CAMPOINT_2P2C",
        "SET_CAMPOINT_1P2C",
        "CAM_POINT_PER",
        "CAM_TARGET_PER",
        "SET_CAM_POINT_LENGTH",
        "SET_CAM_OFFSET",
        "START_WIPER",
        "CREATE_TRAIN_ORG",
        "ORG_SET_RAIL",
        "ORG_ADD",
        "SET_CAMPOINT_K",
        "ORG_SET_POS",
        "ORG_SET_FOG",
        "ORG_RELEASE",
        "PLAY_FTV_END",
        "CNG_TRAIN_MAT_COL",
        "CNG_ORG_MAT_COL",
        "IS_CAUTION",
        "ENDWAIT_COMIC",
        "SET_COMIC_BG_COLOR",
        "TX_2_TRAIN",
        "CHANGE_MT_COL_TRAIN",
        "CNG_MT_COL",
        "RETURN",
        "ReLoadSE",
        "BASE_POINT_CAM",
        "STOP_3D",
        "STOP_STAGE_BGM",
        "TRAIN_UD",
        "SET_CAM_TARGET_OFFSET",
        "SET_CAM_POINT_1T_ROT",
        "SET_CAM_T_LENGHT",
        "SET_CAM_T_ROT_X",
        "SET_CAM_T_ROT_Y",
        "SET_CAM_T_OFFSET",
        "NO_OUTRUN",
        "SET_WHEEL_FIRE",
        "RELOAD_OP_TRAIN",
        "BackR_Drift",
        "BackL_Drift",
        "CHK_MOTION",
        "ORG_SET_STYLE_POS",
        "RECREATE_TRAIN",
        "SET_CAMPOINT_1P2T",
        "BUFF_TO_SC_CAM_POS",
        "SC_ORG_MODE_CHANGE",
        "SC_ORG_INIT_POS",
        "SC_ORG_SET_POS",
        "SC_ORG_SET_ROT",
        "SC_ORG_SET_X_ROT",
        "SC_ORG_SET_Y_ROT",
        "SC_ORG_SET_Z_ROT",
        "SET_SC_KOTEI_CAM_POS",
        "SET_SC_KOTEI_CAM_T_POS",
        "START_SC_WIPER",
        "SUPER_DRIFT",
        "CNG_TRAIN_NO_MAT_COL",
        "ERR_CMD",
        "K_HN",
        "TO_TRACK_RAIL",
        "IS_NO_DRAMA",
        "CNG_TRAIN_NO_MAT_RGBA",
        "SHOW_RECORD",
        "WAIT_RECORD_END",
        "IB_LI_SET_UPDATE_FLG",
        "PTCL_SCALL",
        "PTCL_COLOR",
        "PTCL_ALPHA",
        "PTCL_DRAWTYPE",
        "PTCL_ANGLE",
        "PTCL_RAND_ANGLE",
        "PTCL_RAND_COLOR",
        "PTCL_RAND_ALPHA",
        "PTCL_RAND_SCALL",
        "IB_ADD_PTCL",
        "PTCL_RAND_TONE_COLOR",
        "IS_ALPHA_END",
        "PTCL_L_POS",
        "PTCL_RAND_L_POS",
        "CREATE_MAT_COLOR_R_INTERLIST",
        "CREATE_MAT_EMISSIVE_R_INTERLIST",
        "SET_MAT_COLOR_R",
        "SET_MAT_COLOR_G",
        "SET_MAT_COLOR_B",
        "SET_MAT_COLOR_LOOP",
        "SET_MAT_EMISSIVE_R",
        "SET_MAT_EMISSIVE_G",
        "SET_MAT_EMISSIVE_B",
        "SET_MAT_EMISSIVE_LOOP",
        "CREATE_MAT_COLOR_G_INTERLIST",
        "CREATE_MAT_EMISSIVE_G_INTERLIST",
        "CREATE_MAT_COLOR_B_INTERLIST",
        "CREATE_MAT_EMISSIVE_B_INTERLIST",
        "CREATE_UV_MOVE_Y",
        "SET_UV_MOVE_Y",
        "SET_UV_LOOP_Y",
        "INDEX_RAND_ROT_X",
        "INDEX_RAND_ROT_Y",
        "INDEX_RAND_ROT_Z",
        "INDEX_RAND_POS_X",
        "INDEX_RAND_POS_Y",
        "INDEX_RAND_POS_Z",
        "RAND_SHOW_MESH",
        "INDEX_RAND_SCALL",
        "ADD_CHILD_OBJ",
        "ADD_OBJ_INDEX",
        "GAS_TARBIN",
        "ENGINE_START",
        "CHANGE_CHILDOBJ_ANIME",
        "IB_SET_W_MT",
        "CHK_OBJ_PARAM",
        "SET_OBJ_PARAM",
        "INDEX_DIR_CAM",
        "CNG_MT_LIGHT",
        "ADD_OBJ_INDEX2",
        "CNG_MT_ALPHA",
        "CREATE_MAT_ALPHA_INTERLIST",
        "SET_MAT_ALPHA",
        "RESTART_MESH_LIST",
        "RAIL_ANIME_CHANGE",
        "STOP_COMIC_SE_ALL",
        "HURIKO",
        "FTV_PLAY_AND_PREV",
        "FTV_END_INHERIT",
        "STATION_NAME_PRIORITY",
        "ALL_FIT",
        "SWAP_TX",
        "CNG_TX",
        "CHK_CAUSE",
        "CNG_ANIME",
        "CHK_OUHUKU",
        "SET_TRAIN_PTCL_AREA",
        "WAIT_DOSAN_LENGTH",
        "END_DOSAN_LENGTH",
        "DOSANSEN",
        "MESH_INDEX_SE_UV_ANIME_FLG",
        "WEATHER",
        "TRAIN_DIR",
        "IS_USE_CHAR",
        "QUICK_SAVE_EVENT",
        "NONE_GOAL",
        "ENGINE_STOP",
        "IS_BTL_MODE",
        "IS_FREE_MODE",
        "FIRST_OBJ_SET_ANIME_SCENE",
        "G_HIDE_MESH",
        "G_SHOW_MESH",
        "STOP_WIPER",
        "TRAIN_ANIME_CHANGE",
        "MESH_INDEX_UV_RESTRT",
        "SET_COMIC_COLOR",
        "CHK_OUTRUN_CNT",
        "CHK_D_AND_NOTCH",
        "ADD_CPU_LEN_OUTRUN",
        "ADD_CPU_SPEED_D_AND_NOTCH",
        "CHK_HIT_CNT",
        "TOP_SPEED_HOSYO",
        "SET_ROOT_BLOCK",
        "RIFT",
        "COLLISION",
        "DIR_VIEW_CHANGE",
        "CHK_RAIL_NO",
        "TRACK_CHANGE",
        "CHK_LENGTH_DIR",
        "CHK_POS_DIR",
        "TRUE_CLASH",
        "KATARIN_RUN",
        "DRAW_UI",
        "STOP_SCRIPT_BGM",
        "SET_STATION_NO",
        "SET_CPU_BREAKE",
        "AMB_ANIME",
        "ONE_DRIFT_FALSE",
        "L_One_Drift",
        "R_One_Drift",
        "Ret_One_Drift",
        "FRONT_JUMP",
        "REAR_JUMP",
        "FRONT_MOVE_X",
        "TRACK_MOVE",
        "TRAIN_JUMP",
        "SET_LIGHT",
        "SET_COL_KASENCHU",
        "SET_KAISO",
        "SET_FOR",
        "CHK_TRAIN_COL",
        "VOL_SCRIPT_BGM",
        "IF_NOTCH",
        "SET_BRIND_SW",
        "SET_MIKOSHI",
        "ADD_FIRE",
        "BREAKE_OR_HIT",
        "OUTRUN",
        "SOFT_ATK",
        "RAIL_STOP",
        "CHANGE_OUHUKU_LINE",
        "BRIND_ATK",
        "OPEN_POS_DLG",
        "PLAY_STAGEBGM_BLOCK",
        "SET_BTL_POINT",
        "CAM_TRAIN",
        "PLAY_SCRIPT_BGM",
        "CNG_FOR",
        "SET_RAILBLOCK_CHECKER",
        "RAIN_SE",
        "TRAIN_STOP",
        "KOTEICAM_BLEND",
        "SCRIPT_RAIN",
        "LINE_CHANGE",
        "WAIT_RAIL_MORE_ONLY",
        "SET_SE_VOL",
        "CAM_TARGET_TRACK",
        "DECAL_D37",
        "DECAL_D39",
        "DECAL_SMOKE",
        "RAIL_PRIORITY",
        "GET_KEY",
        "SHOW_LIGHT",
        "SHOW_IN_LIGHT",
        "FOG_POW",
        "STORY_WIN",
        "RAIN_PARTICLE",
        "D39_FIRE",
        "SET_CPU_SPEED",
        "BODY_AUDIO_PLAY",
        "BODY_AUDIO_STOP",
        "CNG_FADE_SPRITE",
        "RAIL_DRIFT_CHK",
        "INQ_WAIT",
        "CNG_SCCAM_TRAIN",
        "STOP_TRAIN_SE",
        "PLAY_SCRIPT_BGM_TIME",
        "CNG_BODY_COLOR",
        "LOAD_TRAIN",
        "SHOW_BLOCK",
        "UPDATE_LIGHT_FRARE",
        "WAIT_RAIL_MORE_GOTO",
        "CREATE_AURA",
        "AURA_ALPHA",
        "SET_LV_JUMP",
        "CREATE_EFFECT_CAM",
        "TO_EFFECT_CAM",
        "EFFECT_CAM_POW",
        "EFFECT_CAM_COLOR",
        "EFFECT_CAM_ALPHA",
        "HIDE_LIGHT",
        "USE_EFFECT_CAM",
        "USE_EFFECT_CAM_RGB",
        "EFFECT_CAM_RGB",
        "COPY_TRAIN_POS",
        "COL_SET",
        "CNG_CPU_TRAIN",
        "BTN_GOTO",
        "NO_TIMESCALE_KOMA",
        "EFFCAM_NOIZE",
        "EFFCAM_GRI",
        "EFFCAM_BLOCKNOISE",
        "CREATE_TQ5000_FLAGMENT",
        "USE_TQ5000_FLAGMENT",
        "TQ5000_FLAGPOS",
        "HUMIKIRI_VOL",
        "TO_EFFECT_CAM_BODY",
        "TO_NORM_CAM",
        "TO_920",
        "NO_TIMESCALE_FVT",
        "CNG_TARGET_BODY",
        "SC_ADD_POINT",
        "CHK_SC_POINT",
        "KAISO_TO_DUEL",
        "SHOW_ST",
        "ORG_UPDATE",
        "SET_RAILBLOCK_POS",
        "SET_LIGHT_OVER",
        "CREATE_STAFFROLL",
        "STAFFROLL_START",
        "WAIT_STAFFROLL",
        "SC_OUTRUN",
        "CREATE_TAKMIS",
        "SET_TAKMIS_POS",
        "SET_TAKMIS_ALPHA",
        "FRONT_DOOR",
        "SET_KOMA_DEPTH",
        "D37_FIRE",
        "AMB_HIT_WAIT",
        "ShowRecord",
        "FIT_PER",
        "CREATE_COMIC_PC",
        "SET_COMIC_PC",
        "PAUSE_STAGE_BGM",
        "SET_KAKAPO",
        "KOMA_KAKAPO",
        "START_TARBINE",
        "END_TARBINE",
        "TARBINE_FTV_START",
        "TARBINE_FTV_END",
        "STORY_ENGINE",
        "RAND_GOTO",
        "KQ_SOUND",
        "STORY_GOTO",
        "PLAY223HONE",
        "RB26",
        "SCRIPT_CMD_MAX"
    };

    // コンソール出力をUTF-8にする場合にコメントアウトから戻す。このソースも、文字コードUTF-8に変換すること。
    //SetConsoleOutputCP(CP_UTF8);

    int langmode = 0; //言語モード設定、0:日本語、 1: English 、 2:韓国語・・・
    // 引数で言語を当たら得られた場合の処理
    
    #if _MYDEBUG
    cout << "argc: " << argc << endl;
    cout << "argv0: " << argv[0] << endl;
    cout << "argv1: " << argv[1] << endl;
    #endif
    
    if (argc >= 2) {
        string argv1 = argv[1];
        if ( argv1 == "en" ) {
            // 英語
            langmode = 1;
        }
        else if (argv1 == "ja") {
            // 日本語
            langmode = 0;
        }
        else if (argv1 == "kr") {
            // 韓国語、Discord で韓国語って見かけたから。
            langmode = 2;
        }
        else if (argv1 == "cn") {
            // 中国語。
            langmode = 2;
        }
        //必要な言語があったらもっとelse if 文を足す
        else if (argv1 == "/help") {
            //ヘルプを印刷する
            cout << "Usage: script.exe <LangageCode: en , ja , ....> <comic~.bin>" << endl;
            cout << "使い方： script.exe <言語コード: en 、 ja 、・・・> <comic~.bin>" << endl;
            //system("pause");//続行するには～のメッセージを出す。自動化の際はコメントアウトすること。
            return 0;
        }
        else {
            // 解析不能な引数が与えられたら。
            cout << "引数で与えられた言語が特定できませんでした。( The language given in the argument could not be identified. )" << endl;
            cout << "デフォルトの日本語を使用します。( Use default  Japanese language. )" << endl;
            langmode = 0; //デフォルトの0
        
        }
    }

    /* ユーザーに、 comic～.bin を指定してもらう。 */
    string sbuf;
    string input;
    cout << "DEND COMIC SCRIPT ver1.1.4..." << endl;
    if ( argc >= 3 ) {
        // コマンドライン引数で与えられたファイルを読む
        if (langmode == 1) {
            cout << "Reads the file given by the command line argument. : " << argv[2] << endl ;
        }else{
            cout << "コマンドライン引数で与えられたファイルを読み込みます。" << endl;
        }
        input = string( argv[2] );
    }
    else {
        // ユーザー指定のファイル名を読み込む
        if (langmode == 1) {
            cout << "Input comic's bin filename. : ";
        }
        else {
            cout << "comicのbinファイル名を入力してください: ";
        }

        cin >> input;

    }

    ifstream fin(input, ios::in | ios::binary);
    if (!fin) {
        // 指定されたファイルが見つからない場合
        cin.ignore();
        if (langmode == 1) {
            cout << "The specified file was not found.  Exit this program. " << endl;
        }
        else {
            cout << "指定されたファイルが見つかりません。終了します。" << endl;
        }
        //getchar();
        system("pause");//続行するには～のメッセージを出す。自動化の際はコメントアウトすること。
        return -1;
    }

    // 以下、 comic～.bin が見つかった場合、 ファイルの中身を全部読みだす。
    //printf("見つけました！\n\n");
    if (langmode == 1) {
        cout << "Found It! " << endl << endl;
    }
    else {
        cout << "見つけました！" << endl << endl;
    }
    fin.seekg(0, ios::end);
    int size = fin.tellg();
    fin.seekg(0, ios::beg);
    char* str = new char[size];
    fin.read(str, size);

    #if _MYDEBUG
    cout << "size: " << size << endl;
    cout << "str_len: " << strlen(str) << endl;
    cout << "str: " << endl << str << endl;
    #endif

    fin.close();

    // データ読み取り方法の設定
    int slowFlag;
    if (langmode == 1) {
        cout << " Do you want to read ReadComicData line by line? (Y/N): ";
    }
    else {
        cout << "ReadComicDataを１行ずつ読みますか？(Y/N): ";
    }
    while (true) {
        cin >> input;

        if (input == "Y" || input == "y") {
            slowFlag = 1;
            break;
        } else if (input == "N" || input == "n") {
            slowFlag = 0;
            break;
        } else {
            cin.ignore();
            if (langmode == 1) {
                cout << "Input error: Please retry input 'Y' or 'N' : ";
            }
            else {
                cout << "入力エラー！改めて入力してください：";
            }
        }
    }

    int index = 16;
    char* buf = new char[index+1](); // new した char配列10個を初期化する
    memcpy(buf, &str[0], index);
    buf[index + 1] = '\0';//memcpyしたら、末尾に番兵（'\0'）を置くこと！
    sbuf = string(buf);

    #if _MYDEBUG
    cout << "sizeof_char: " << sizeof(char) << endl;
    cout << "buf_len: " << strlen(buf) << endl;
    cout << "buf: " << buf << endl;
    cout << "sbuf_len: " << sbuf.length() << " /sbuf_size: " << sbuf.size() << endl;
    cout << "sbuf: " << sbuf << endl;
    #endif

    // 電車でDのコミックスクリプトかどうか、ヘッダー判定を行う。
    if (sbuf != "DEND_COMICSCRIPT") {
        cin.ignore();
        if (langmode == 1) {
            cout << "The specified file was Don't DEND comic script. Exit this program. " << endl;
        }
        else {
            cout << "DEND comic scriptファイルではありません。終了します。" << endl;
        }
        //getchar();
        system("pause");//続行するには～のメッセージを出す。自動化の際はコメントアウトすること。
        return -1;
    }
    delete buf;

    // ここから、解析本体
    index++;
    cout << "ReadComicImg..." << endl;
    int imgCnt = str[index];
    index++;
    for (int i = 0; i < imgCnt; i++) {
        int b = str[index];
        index++;
        char* buf = new char[b+1];
        memcpy(buf, &str[index], b);
        buf[b] = '\0';
        cout << i << " -> ";
        cout << buf << endl;
        index += b;
        delete buf;
    }
    cout << '\n';

    cout << "ReadComicSize..." << endl;
    int imgSizeCnt = str[index];
    index++;
    for (int i = 0; i < imgSizeCnt; i++) {
        cout << (int)str[index] << " -> ";
        index++;
        for (int j = 0; j < 4; j++) {
            float* f = (float *)&str[index];
            cout << *f << ", ";
            index += 4;
        }
        cout << '\n';
    }
    cout << '\n';

    cout << "ReadSE..." << endl;
    int secnt = str[index];
    index++;
    for (int i = 0; i < secnt; i++) {
        int b = str[index];
        index++;
        char* buf = new char[b+1];
        memcpy(buf, &str[index], b);
        buf[b] = '\0';
        cout << i << " -> " << buf;
        index += b;
        cout << ", " <<  (int)str[index] << endl;
        index++;
        delete buf;
    }
    cout << '\n';

    cout << "ReadBGM..." << endl;
    int bgmcnt = str[index];
    index++;
    for (int i = 0; i < bgmcnt; i++) {
        int b = str[index];
        index++;
        char* buf = new char[b+1];
        memcpy(buf, &str[index], b);
        buf[b] = '\0';
        cout << buf;
        index += b;
        cout << ", " <<  (int)str[index] << endl;
        index++;
        index += 4;
        index += 4;
        delete buf;
    }
    cout << '\n';

    cout << "ReadComicData..." << endl;
    index++;

    buf = new char[2];
    memcpy(buf, &str[index], 2);
    short* p_num = (short *)buf;
    short num = *p_num;
    index += 2;
    delete buf;

    int count = 0;
    cin.ignore();
    for (int i = 0; i < num; i++) {
        if (index >= size) {
            if (langmode == 1) {
                cout << "Attention! The number of commands you set (" << num << ") is trying to read more than the number of commands you wrote (" << count << ")." << endl;
            }
            else {
                cout << "注意！設定したコマンド数(" << num << ")は、書き込んだコマンド数(" << count << ")より多く読もうとしています。" << endl;
            }
            //getchar();
            system("pause");//続行するには～のメッセージを出す。自動化の際はコメントアウトすること。
            return 0;
        }
        cout << "No." << dec << i << " -> index(";
        cout << hex << index;
        cout << ")" << endl;
        char* buf = new char[2];
        memcpy(buf, &str[index], 2);
        short *p_num2 = (short *)buf;
        short num2 = *p_num2;
        index += 2;

        if (num2 < 0 || num2 >= CMD_MAX) {
            if (langmode == 1) {
                cout << "This is a command number that is not defined (" << dec << num2 << "). Exit reading." << endl;
            }
            else {
                cout << "定義されてないコマンド番号です(" << dec << num2 << ")。読込を終了します。" << endl;
            }
            //getchar();
            system("pause");//続行するには～のメッセージを出す。自動化の際はコメントアウトすること。
            return 0;
        }
        delete buf;
        
        cout << "cmd -> " << cmd[num2] << "(";
        cout << dec << num2 << ")" << endl;
        int b = str[index];
        index++;
        if (b >= 16) {
            cout << "script Error!" << endl;
            b = 16;
        }
        cout << "cmd_cnt -> " << b << endl;
        cout << "cmd_param -> [";
        for (int j = 0; j < b; j++) {
            float* f = (float *)&str[index];
            cout << *f << ", ";
            index += 4;
        }
        cout << "]" << endl;
        if (slowFlag) {
            //getchar();
            system("pause");//続行するには～のメッセージを出す。自動化の際はコメントアウトすること。
        } else {
            cout << '\n';
        }
        count++;
    }
    // 解析の本体ここまで ---


    if (langmode == 1) {
        cout << "Loaded successfully. Exit this program." << endl;
    }
    else {
        cout << "正常に読み込みできました。終了します。" << endl;
    }
    if (index < size) {
        if (langmode == 1) {
            cout << "Warning! The number of commands you set (" << count << ") is less than the number of commands you wrote." << endl;
        }
        else {
            cout << "注意！設定したコマンド数(" << count << ")は、書き込んだコマンド数より少なく設定されています" << endl;
        }
    }
    //getchar();
    system("pause");//続行するには～のメッセージを出す。自動化の際はコメントアウトすること。

    return 0;
}