//参考記事
//https://liginc.co.jp/282918
//連動させるサイト
//http://jsdo.it/wamisnet/nefry-milkcocoa
#include <Nefry.h>
#include <Nefry_Milkcocoa.h>
 
Nefry_Milkcocoa *milkcocoa;
//https://liginc.co.jp/282918
 //http://jsdo.it/wamisnet/nefry-milkcocoa
char *datastore;
void onpush(DataElement *elem) {//MilkcocoaのOn関数と同一
//データストアにデータが届いたときに呼び出される
 Nefry.print("onpush:");
 Nefry.println(elem->getInt("sw"));//swというデータがあるとき表示されます
}
 
void setup() {
  Nefry.setProgramName("SWを押すとMilkcocoaでWebページを変更させる");
 milkcocoa->print();//Setup ModuleページにAPPIDの表示をする
 milkcocoa = Nefry_Milkcocoa::begin();//milkcocoaと接続に必要になる処理をします。
 datastore = Nefry.getConfStr(3);//Setup Moduleページに入力されたデータストア名を保存します。
 Nefry.println( milkcocoa->on( datastore, "push", onpush) ? "Milkcocoa onPush OK" : "Milkcocoa onPush NG" );//on関数を有効にします。
}
bool flg, old;
void loop() {
 if ( (flg = Nefry.push_SW()) != old) {//ボタンの状態が前回と異なるとき 
   Nefry.println( milkcocoa->loop(10000)? "Milkcocoa Connect OK" : "Milkcocoa Connect NG" );//10秒以内にMilkcocoaに接続できればokと表示されます。
   DataElement elem = DataElement();
   elem.setValue("sw", flg );//スイッチの状態を送信できる形に変換
   old = flg;//今の状態を保存
   milkcocoa->push(datastore, &elem);//Milkcocoaに送信
 }
}
