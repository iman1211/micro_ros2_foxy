// ====================================================
//                PARSING DATA SerialUSB (string & int)
// ====================================================
 
String dataIn;
String dt[10];
int i;
boolean parsing=false;
 
void setup() 
{
    SerialUSB.begin(9600);
    dataIn="";
}
 
void loop() 
{
     if(SerialUSB.available()>0)
     {
           char inChar = (char)SerialUSB.read();
           dataIn += inChar;
           if (inChar == '\n') {parsing = true;}
     } 
     else
     {
      delay(5000);
      SerialUSB.print("data 1 : ");
      SerialUSB.print(dt[0]);
      SerialUSB.print("\n");
      SerialUSB.print("data 2 : ");
      SerialUSB.print(dt[1].toInt());
      SerialUSB.print("\n");
      SerialUSB.print("data 3 : ");
      SerialUSB.print(dt[2].toInt());
      SerialUSB.print("\n");
      SerialUSB.print("data 4 : ");
      SerialUSB.print(dt[3].toInt());
      SerialUSB.print("\n");
      SerialUSB.print("data 5 : ");
      SerialUSB.print(dt[4].toInt());
      SerialUSB.print("\n\n");
     }
     
     if(parsing)
     {
           parsingData();
           parsing=false;
           dataIn="";
     } 
}
 
void parsingData()
{
      int j=0;
      //kirim data yang telah diterima sebelumnya
      SerialUSB.print("data masuk : ");
      SerialUSB.print(dataIn);
      SerialUSB.print("\n");
      //inisialisasi variabel, (reset isi variabel)
      dt[j]="";
      //proses parsing data
      for(i=1;i<dataIn.length();i++)
      {
             //pengecekan tiap karakter dengan karakter (#) dan (,)
             if ((dataIn[i] == '#') || (dataIn[i] == ','))
             {
                   //increment variabel j, digunakan untuk merubah index array penampung
                   j++;
                  dt[j]=""; //inisialisasi variabel array dt[j]
             }
             else
             {
                  //proses tampung data saat pengecekan karakter selesai.
                  dt[j] = dt[j] + dataIn[i];
             }
      }
}
