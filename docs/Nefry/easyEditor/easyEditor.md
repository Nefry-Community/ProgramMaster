# EasyEditor

<!-- プログラムの内容を記載してください。  -->
EasyEditorについては[こちら](http://qiita.com/wamisnet/items/0a229cca664b189eb518)を参考にしてください。  


|実装済みコード|引数を含める|具体例|何ができるのか|
|:---:|:---:|:---:|:---:|
|digitalWrite|digitalWrite(ピン,HIGH or LOW);|digitalWrite(D5,HIGH);|HIGHかLOWか出力できる|
|digitalRead|digitalRead(ピン)|digitalRead(D4);|HIGHかLOWか取得できる|
|analogWrite|analogWrite(ピン,0-1023);|analogWrite(D3,900);|D0-D5を0-1023段階で出力できる|
|analogRead|analogRead();|analogRead();|A0ピンの状態を取得できる|
|pwmWrite|pwmWrite(ピン,0-99)|pwmWrite(D0,90);|CocoaBit向けのアナログ出力|
|tone|tone(ピン,周波数,何ミリ秒鳴らすか)|tone(D0,262,500);|音を鳴らす|

Tone関数については[こちら](/tone)にまとめておきました。

## 必要なもの、ツール

<!-- 表 -->

## 動作確認

|Nefry|
|:---:|
|![NefryOK](../../img/ic/nefry-ok.png)|

## ダウンロードリンク
ダウンロードリンクとは、Nefry Web ConfigのWeb updateのページのURIに入力することでNefry自身がプログラムをダウンロードして更新ができるものになります。

Nefry向け

!!!link
	/Nefry/easyEditor

CocoaBit向け

!!!link
	/CocoaBit/easyEditor

それぞれの違いはピン配置の違いによるものです。


##サンプルプログラム

<!-- 接続例があればなおよい -->

<!-- gh-pages以下の部分を変更してください。 -->
<script src="http://gist-it.appspot.com/github/Nefry-Community/ProgramMaster/blob/gh-pages/Nefry/easyEditor/easyEditor.ino">
</script>


