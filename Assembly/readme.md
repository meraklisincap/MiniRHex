# MiniRHex Montaj Talimatları

1. Solidworks ve mevcut CAD dosyaları
 * Güncellenen veya değiştirilen SolidWorks parçaları buraya yüklenecektir.
  
2. Gerekli parçaları ve eşyalara bağlantıları görmek için MiniRhexHardware dosyasına bakın.
  
3. Bir Ultimaker 3'e erişiminiz varsa, MiniRhex_full_print_compressed.gcode.gz olarak adlandırılan / CAD / STL içindeki genişletilmiş yazıcı g kodunu kullanarak yükleyin ve yazdırın.
   Aksi takdirde, aşağıdakileri (PLA) yazdırın, .stl dosyaları / CAD / STL içinde bulunabilir.
 * 6 (servo sleeve.STL), En iyi sonuçlar için yapı plakasında arka yüze baskı yapın.
 * 4 (shaft-edge.STL)
 * 2 (shaft-mid.STL)
 * 1 (Battery case.STL)
 * 6 (leg.STL)
 
 Yazdırmak için kullanılan beklenen PLA miktarı şudur:
 * 6 (6 sleeves) = 66g
 * 4 (4 shaft edges) = 12g
 * 2 (2 shaft-mid parts) = 10g
 * 1 (1 case) = 17g
 * 6 (6 legs) = 12g
 
Toplam miktar 117g.
 
 Yazdırdıktan sonra, servo kovanlarının, şaft kenarı parçalarının ve şaft orta parçalarının içinde destekler vardır. Devam etmeden önce baskıların içindeki destekleri çıkardığınızdan emin olun. Buna benzemeliler:
 
 ![Shaft-mid](Images/final_mid.jpg)
 
 ![Shaft-edge](Images/final_else.jpg)
 
 ![Servo_sleeve](Images/final_servo_sleeve.jpg)
 
Sonuç olarak, parçalar aşağıdaki gibi görünmelidir:
 
 ![herşey](Images/final_all.png)
  
4. Base.sldprt dosyasını açın ve bir .dxf dosyası olarak kaydedin. 3 mm kalınlığında akrilik kesmek için bu dosyayı kullanın.
robot için temel olarak hizmet vermektedir.

Vidaların deliklerden geçtiğinden emin olun. Değilse, devam etmeden önce onları delin.

5. Anakartı kullanıma hazırlayın.
 * Akü soketini bir pozitif iğne deliğine ve bir negatif iğne deliğine lehimleyin.
  güç için tahtadaki yer aşağıda gösterilmiştir:
  
  ![Güç pin yeri](Images/MiniRHex_powerpins.png)
  
6. Öncelikle, USB girişini dışarı bakacak şekilde pil kutusunu ve anakartı prize takın (tam MiniRHex düzeni için 16. adıma bakın).
 * Bağlantılar:
  * Pil kutusu: M3 düğme kafası x 10 mm, M3 somunu
  * Ana kart: M3 boşluk, M3 düğme kafası x 10 mm, M3 kilit somunu
  * Pil kutusu vakfın merkezine yakın.
  * Anakartın mikro-USB bağlantı noktası dışarı dönük olmalıdır.
  * Ana kart robotun önüne doğru olacaktır.
  
  Somunları tahtanın üzerine yerleştirin, böylece MiniRHex'in hareketine engel olmaz. Somunun tahtanın altına yerleştirilmesi önerilmez.
  
  Anakartı yerleştirmek için, anakart ile akrilik taban arasına ara parçayı, ardından anakartın üzerine somunu yerleştirin.
  
7. Ardından, Plastidip (daldırma veya sprey) kullanarak bacakları hazırlayın ve altı yüzeyin her birinin yaklaşık% 75'ini kaplayın
Her bir bacak üzerinde yüksek sürtünme yüzeyi oluşana kadar bacaklar.
  * Her kat arasında en az bir saat kurumaya bırakınız.
  * Dipin bacağın etrafına eşit şekilde kaplandığından emin olun.
  * Vidaların geçiş deliklerini kapatmayın.
  
  Bacaklar aşağıdaki gibi görünmelidir:
  
  ![Ayaklar Son](Images/final_leg.jpg)
  
8. Altı bacağın dördünü kenar millerine (daha kısa miller) bağlayın.
   
  Üç boyutlu baskının doğası gereği, bacakların rahatça oturabilmesi veya bacaklardaki delikleri açması için bacak millerinizi aşağıya eğmeniz gerekebilir.
   
   Sonra, bir m3 musluğu kullanarak bacak millerine dokunun.
   
   Bir m3 vida kullanarak bacakları bacak millerine bağlayın.

  * Ayağı deliklerin içinden milin oyuk kısmındaki deliklerle aynı hizaya getirin.
  * Bacağın hizalı olduğundan ve mile yaslandığından emin olun.
  * Bağlantı: M3 soket kafası x 10 mm
  * Aşağıda gösterildiği gibi her yöne bakan iki bacak olduğundan emin olun.
  
9. Diğer iki ayağı orta millere (daha uzun şaft) bağlayın.

  Benzer şekilde, ilk önce bacak millerini eğmeniz ve delmeniz gerekebilir.
   
  Yine, vidaları takmadan önce bacak millerine dokunun. 
   
  * Ayağı deliklerin içinden milin oyuk kısmındaki deliklerle aynı hizaya getirin.
  * Bacağın hizalı olduğundan ve mile yaslandığından emin olun.
  * Bağlantı: M3 soket kafası x 10 mm
  * İki bağlantıdan biri için bacağın yönünü değiştirdiğinizden emin olun.
  Aşağıda gösterildiği gibi.
  
  ![Bacak Yönü](Images/minirhex_motor_orientation.JPG)
  
10. Her mil-ayak aparatını Dynamixel XL-320 servo motora bağlayın.
  * Yönlendirme: Her bacağın oluşturduğu yarım dairenin robotun önüne baktığından emin olun:
  anakart ile yana doğru.
  * Servo kornadaki merkez vidayı sökün ve kornadan ayırın.
  * Korna tarafında bir onay işareti ve karşı tarafta iki onay işareti olacaktır. Bacakları servo kornasına hizalarken, servo kornasını motora geri yerleştirirken, tek onay işaretinin aşağıya bakacak şekilde, servo tabanına doğru baktığından emin olun.
  * Servo boynuzu üzerindeki 4 delikten milin üzerine çekilmiş 4 adet hizalayın
  Yüz (mil uzunluğu önemli değil).
  * Kornayı (şimdi bacak aparatına bağlı) servo gövdesindeki anahtarına hizalayın.
    * Korna gövdeye tam temas ettiğinde, korna / mil / bacak aparatını bağlayın.
    servo motora
    * Bağlantı: McMaster'dan M2.5x25 cıvatalar

11. Her servoyu bir servo kovanın içine kaydırın.

Her servo manşonu temele bağlamadan önce, servo ID'lerinin her birini verilen tellerle ayrı ayrı ana karta bağlayarak yapılandırın. 

[Servo ID'lerini Yapılandırma] ile ilgili talimatlar (https://github.com/robomechanics/MiniRHex#configure-servo-ids).

12. Her servo kovanı temele bağlayın.
  *Yönlendirme: Tüm bacakların öne dönük olduğundan emin olun (yarım daire ana karta bakar).
  * Bağlantı: M3 düğme kafası x 10 mm, M3 somun
  
  Yine, M3 somunların, levhanın dibine zıt olarak levhanın üzerine yerleştirilmesi önerilir.
  
13. Servoları anakarta bağlayın.
  * Kabloların bacak dönüşüne engel olmayacak şekilde bağlayın.
14. Bataryaları şarj edin ve voltajı kontrol edin.
  * Maksimum voltaj:  8.4V
  * Altta şarj:  7.0V
  * Aşağıda varsa atın: 5.0V

15. Mikro USB bağlantı noktasını kullanarak kod yükleyin. Daha detaylı talimatlar burada bulunabilir. (https://robomechanics.github.io/MiniRHex).

16. Servolarla gelen elektronik kabloları alın ve aşağıdaki gibi bağlayın.
![bağlantı şeması](Images/MiniRHex_wiring_diagram.png)
 
 
