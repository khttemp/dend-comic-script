# dend-comic-script

* ja（ 日本語 ）

## 概要

dend-comic-script は、電車でD 全作品のコミックスクリプトをダンプするソフトウェアである。

## 動作環境

* 電車でDが動くコンピュータであること
* OS: Windows 10 64bit の最新のアップデートであること
* OSの端末が日本語に対応していること

※ MacOS 、 Linux などの Unix 系 OS での動作は保証できない。


## 免責事項

このプログラムを使用して発生したいかなる損害も製作者は責任を負わない。

このプログラムを実行する前に、自身のコンピュータのフルバックアップを取得して、
安全を担保したうえで実行すること。
このプログラムについて、電車でD 作者である、地主一派へ問い合わせてはいけない。

このソフトウェアの更新やバグ取りは、作者の義務ではなく解消努力目標とする。
Issue に上げられたバグ情報が必ず修正されるものではない。

* ライセンス：GPL

電車でD の正式なライセンスを持っていること。




東京地裁第一法廷

このプログラムのバイナリを実行した時点で、この規約に同意したものと見なす。


## コンパイル方法

* Mingw64 の場合

````
> g++ script.cpp -o script -static-libgcc -static-libstdc++

````

* VisualC++ ( cl.exe ) の場合

````
> cl.exe /MT script.cpp /Fe:script.exe
````

* Intel OneAPI ( icl.exe ) の場合

````
> icl.exe /MT /O2 script.cpp /Fe:script.exe
````

## 実行方法

以下に、実行例を示す。コマンドオプションや、フォルダーなどは、自分のコンピュータの設定に沿って、
適宜読みかえること。

コマンドプロンプトか PowerShell を起動し、 script.exe のあるフォルダーに移動する

````
> cd /d "C:\Users\flandre\Desktop\dend-comic-script"
```

script.exe を実行する

````
> script.exe
DEND COMIC SCRIPT ver1.1.4...
comicのbinファイル名を入力してください: comic2900.bin （ ←自分で入力する ）
見つけました！

ReadComicDataを１行ずつ読みますか？(Y/N)N （ ←自分でYかNを入力する ）
（ 設定値が出力される ）
正常に読み込みできました。終了します。


````


## よくある質問

* Q. 日本語が文字化けする
  * A. コマンドプロンプトのフォントを日本語の表示できる、「MS ゴシック」などに変更する。
  * 英語OSなどで、日本語フォントが無い場合、コマンドプロンプトに対応できる日本語フォントは、自分で入手すること。



以上。



* English（ 英語 ）

## Abstract

This software is a .

## System Requirements

* 
* 
* 



## Disclaimers

* License： 

## Compilation method

* case : Mingw64 

````
> g++ script.cpp -o script -static-libgcc -static-libstdc++

````

* case : VisualC++ ( cl.exe ) 

````
> cl.exe /MT script.cpp /Fe:script.exe
````

* case : Intel OneAPI ( icl.exe ) 

````
> icl.exe /MT /O2 script.cpp /Fe:script.exe
````

## Execution method

Run Command prompt or PowerShell. 
Change to directory , the folder containing script.exe .

````
> cd /d "C:\Users\flandre\Desktop\dend-comic-script"
```

run script.exe .

````
> script.exe
DEND COMIC SCRIPT ver1.1.4...
comicのbinファイル名を入力してください: comic2900.bin （ ←Input your self. ）
見つけました！

ReadComicDataを１行ずつ読みますか？(Y/N)N （ ←Input your self which Y or N . ）
（ 設定値が出力される ）
正常に読み込みできました。終了します。


````


## FAQ





That's all. Have a fun.



