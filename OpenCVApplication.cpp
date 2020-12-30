// OpenCVApplication.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <fstream>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    string filename = "title.png";

    std::ifstream ifs(filename);
    if (ifs.is_open())
    {
        cout << "ファイルは見つかりました" << endl;
    }
    else {
        cout << "ファイルは見つかりません" << endl;
    }


    Mat image;
    image = imread(filename, IMREAD_COLOR);
    if (image.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }
    namedWindow("Display window", WINDOW_AUTOSIZE);
    imshow("Display window", image);

    cout << "Hello World!\n";

    waitKey(0);
    return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
