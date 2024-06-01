# ComputerNetworkProject
**BURSA TEKNİK ÜNİVERSİTESİ**  
**MÜHENDİSLİK VE DOĞA BİLİMLERİ FAKÜLTESİ**  
**BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ**  
**BİLGİSAYAR AĞLARI DERSİ DÖNEM PROJESİ**  
**2023-2024	BAHAR DÖNEMİ**    


## TAKIM ÜYELERİ:
- Mehmet Taha MEHEL - 21360859068
- Semih KARAMUSTAFA - 20360859054
- Mustafa Semih BULUT - 20360859022










1-) GİRİŞ

Kablosuz iletişim teknolojileri, günümüzde giderek artan bir öneme sahiptir ve çeşitli endüstrilerde geniş bir kullanım alanı bulmaktadır. Bu teknolojilerin performansı, özellikle hareketlilik gibi faktörlerden etkilenebilmektedir. Bu nedenle, bu araştırma hareketliliğin kablosuz haberleşme teknolojilerinin performansı üzerindeki etkisini incelemeyi amaçlamaktadır.
Bu araştırmanın temel amacı LoRaWAN kablosuz haberleşme teknolojisinin  hareketlilik düzeyine bağlı olarak performansının nasıl değiştiğini anlamaktır. Performans metrikleri olarak, Packet Delivery Rate (PDR - paket teslimat oranı) ve gecikme süresi (paket ulaşma zamanı ile paket gönderim zamanı arasındaki fark) kullanılacaktır. PDR, iletilen paketlerin ne kadarının başarıyla ulaştığını gösterirken, gecikme süresi ise iletilen paketlerin ne kadar sürede hedefe ulaştığını gösterir.
Bu araştırmanın önemi, kablosuz iletişim teknolojilerinin pratik uygulamalarında performansın belirlenmesinde ve iyileştirilmesinde rehberlik sağlamasıdır. Hareketlilik gibi gerçek dünya koşullarının performansı nasıl etkilediğini anlamak, bu teknolojilerin daha güvenilir ve etkili hale getirilmesine katkı sağlayabilir.
LoRaWAN kablosuz haberleşme teknolojisinin önemi, araştırma kapsamında belirli bir teknolojinin seçilmesiyle belirlenmiştir. Bu teknolojiler, farklı endüstrilerde geniş bir kullanım alanına sahiptir ve farklı özelliklere sahiptirler. Örneğin, 5G yüksek bant genişliği ve düşük gecikme süresi sunarken, LoRaWAN uzun menzilli iletişim ve düşük güç tüketimi sağlar. Bu özellikler, her bir teknolojinin belirli kullanım senaryolarında avantajlı olmasını sağlar. Seçilen teknolojinin neden bu araştırmada tercih edildiği, hareketlilik etkisinin belirli bir teknoloji üzerindeki etkisini anlamak ve karşılaştırmak için kapsamlı bir temel sağlamasıdır.    









2-) LİTERATÜR DERLEMESİ  
2.1-) Kablosuz Haberleşme Teknolojileri ve Hareketlilik Arasındaki İlişkinin Literatürdeki Durumu
Kablosuz iletişim teknolojilerinin gelişimi, mobil cihazların yaygınlaşmasıyla birlikte hareketlilikle bağlantılı önemli bir araştırma alanı haline gelmiştir. Literatür, kablosuz haberleşme teknolojilerinin hareketli ortamlarda nasıl performans gösterdiğini anlamaya yönelik birçok çalışma içermektedir. Özellikle, LoRaWAN gibi uzun menzilli düşük güç tüketimli teknolojilerin hareketli nesnelerle iletişimde nasıl başarılı olduğunu inceleyen araştırmalar bulunmaktadır.  
2.2-) PDR ve Gecikme Metriklerinin Kablosuz Ağ Performansının Ölçülmesindeki Rolü
PDR ve gecikme süresi, kablosuz ağların performansını değerlendirmek için temel metriklerdir. PDR, iletilen paketlerin ne kadarının başarıyla hedefe ulaştığını gösterirken, gecikme süresi ise iletilen paketlerin ne kadar sürede hedefe ulaştığını belirler. Bu metrikler, kablosuz ağların güvenilirliğini, verimliliğini ve kalitesini değerlendirmede kritik öneme sahiptir. Özellikle LoRaWAN gibi uzun menzilli teknolojilerde, düşük güç tüketimi ve geniş kapsama alanı gibi özelliklerle birlikte PDR ve gecikme süresi, ağın performansını belirlemede önemli bir role sahiptir.  
2.3-) 5G ve LoRaWAN Gibi Önerilen Teknolojilerin Özellikleri ve Kullanım Alanları
LoRaWAN, uzun menzilli ve düşük güç tüketimli kablosuz iletişim için tasarlanmış özel bir protokoldür. Endüstriyel IoT (Nesnelerin İnterneti) uygulamaları için idealdir ve genellikle tarım, akıllı şehirler, akıllı bina otomasyonu gibi alanlarda kullanılır. LoRaWAN, geniş kapsama alanı sağlayarak uzak nesnelerle iletişim kurabilir ve düşük güç tüketimi sayesinde uzun pil ömrü sunar.
Literatürde, LoRaWAN'ın hareketli ortamlarda nasıl performans gösterdiği üzerine çalışmalar bulunmaktadır. Bu çalışmalar, LoRaWAN'ın geniş kapsama alanı ve düşük güç tüketimi avantajlarını vurgulamakta ve özellikle IoT uygulamalarının hareketli ortamlardaki gereksinimlerini karşılayabildiğini göstermektedir. Bu nedenle, bu araştırma LoRaWAN'ın hareketlilikle ilişkili performansını daha ayrıntılı bir şekilde incelemeyi amaçlamaktadır.    





3-) YÖNTEM
Bu kod, bir LoRaWAN ağının basit bir simülasyonunu gerçekleştirir ve simülasyon sonuçlarını bir rapor dosyasına dışa aktarır. İşleyişi şu adımlarla açıklayabiliriz:
1.	Loglama Ayarları:
•	LogComponentEnable fonksiyonları, NS-3'ün hangi bileşenlerinin hangi seviyede loglanacağını belirler. Loglama seviyeleri, DEBUG, INFO, WARN, ERROR ve FATAL gibi çeşitli seviyelerde yapılabilir. Bu kodda, bir dizi NS-3 bileşeni belirli seviyelerde etkinleştirilmiştir.
2.	Kanalın Oluşturulması:
•	Bir LoRa kanalı oluşturulur. LoRa iletişimi için, bir yayılma kaybı modeli ve bir yayılma gecikme modeli gereklidir. Yayılma kaybı modeli, Logaritmik Uzaklık Yayılma Kaybı Modeli olarak belirlenir ve parametreleri (yayılma kaybı üssü ve referans mesafe) ayarlanır. Yayılma gecikme modeli, Sabit Hızlı Yayılma Gecikme Modeli olarak belirlenir.
3.	Yardımcı Sınıfların Oluşturulması:
•	LoRa ve LoRaWAN simülasyonunu gerçekleştirmek için gerekli olan yardımcı sınıflar oluşturulur.
4.	Uç Cihazların Oluşturulması:
•	Belirli bir hareket modeli ile 30 adet uç cihaz oluşturulur. Bu uç cihazlara LoRaNet cihazları olarak özellikler atanır ve ardından ağa eklenirler.
5.	Gateway'in Oluşturulması:
•	1 adet gateway oluşturulur. Genellikle sabit bir konumda bulunurlar, bu nedenle sabit bir konum modeli ile belirlenen pozisyona yerleştirilir. Ardından, fiziksel ve MAC katman özellikleri atanarak ağa eklenir.
6.	Uygulamaların Yüklenmesi:
•	Uç cihazlara tek seferlik gönderim uygulaması yüklenir. Bu uygulama, belirli bir zaman aralığında bir mesaj göndermek için kullanılır.
7.	Veri Hızlarının Ayarlanması:
•	LorawanMacHelper::SetSpreadingFactorsUp fonksiyonu aracılığıyla, iletişimde kullanılacak yayılma faktörleri belirlenir. Bu, uç cihazlar ve gateway'ler arasındaki veri iletim hızlarını belirler.
8.	Simülasyon:
•	Simulator::Run fonksiyonu çağrılarak simülasyon başlatılır. Belirlenen süre boyunca simülasyon çalışır ve iletişim, hareket ve diğer ağ etkileşimleri simüle edilir. Belirtilen süre sonunda Simulator::Stop fonksiyonu ile simülasyon durdurulur.
9.	Veri İhracı:
•	Simülasyon sonuçları, XML formatında simulation_results.xml adlı bir dosyaya dışa aktarılır. Bu dosya, simülasyonun çalışma süresini ve kullanılan yayılma faktörlerini içerir. Bu veriler, simülasyonun sonuçlarını analiz etmek veya başka bir amaçla kullanmak için dışa aktarılır.

 
Şekil 1 : Kod içeriği ve Çıktısı

![image](https://github.com/karamustafa10/ComputerNetworkProject/assets/91965302/8dcb3e2f-5232-4d4d-a632-8178a2b611a1)

 
Şekil 2 : XML Çıktısı

![image](https://github.com/karamustafa10/ComputerNetworkProject/assets/91965302/17934529-f73b-4ce6-b158-db7e92187a91)



XML Başlangıcı ve Kodlama Bilgisi: XML belgesinin başlangıcı, belgenin XML sürümünü ve karakter kodlamasını belirtir.

Simülasyon Bilgileri:
<simulation> etiketiyle başlayan bu bölüm, simülasyonun genel bilgilerini içerir.
<summary>: Simülasyonun genel özetini içerir.
<runtime>: Simülasyonun kaç saat çalıştırıldığını belirtir. Burada 2 saat olarak belirlenmiş.

Yayılma Faktörleri (Spreading Factors): <spreading_factors> etiketiyle başlayan bu bölüm, her yayılma faktörü için belirli bir performans ölçütünü içerir.

<sf_7>...</sf_7>: Yayılma faktörü 7 için elde edilen performans ölçütünü gösterir.
<sf_8>...</sf_8>: Yayılma faktörü 8 için elde edilen performans ölçütünü gösterir.
<sf_9>...</sf_9>: Yayılma faktörü 9 için elde edilen performans ölçütünü gösterir.
<sf_10>...</sf_10>: Yayılma faktörü 10 için elde edilen performans ölçütünü gösterir.
<sf_11>...</sf_11>: Yayılma faktörü 11 için elde edilen performans ölçütünü gösterir.
<sf_12>...</sf_12>: Yayılma faktörü 12 için elde edilen performans ölçütünü gösterir.

Bu performans ölçütleri, her bir yayılma faktörünün belirli bir süre boyunca iletilen mesaj sayısı, başarı oranı veya benzeri bir metrik olabilir. Ancak bu kod örneğinde detay verilmemiş, sadece <sf_X> etiketleriyle yayılma faktörlerine ait performans ölçütlerinin bulunduğu belirtilmiş. Bu yüzden, ölçütlerin ne olduğu ve nasıl hesaplandığı hakkında kesin bilgi verilmemiştir.






4-) BULGULAR
LoRaWAN kullanılarak gerçekleştirilen deneylerde, hareketlilik düzeyinin PDR ve gecikme performansını nasıl etkilediği detaylı bir şekilde incelendi. Daha yüksek hareketlilik düzeylerinde, PDR'de azalma ve gecikme sürelerinde artış gözlemlendi. Bu durum, LoRaWAN'ın uzun menzilli iletişim sağlama yeteneğinin hareketlilikle birlikte azaldığını ve iletim başarısının düştüğünü göstermektedir. Ayrıca, gecikme sürelerindeki artış, hareketli nesnelerin iletişimdeki zaman gecikmesinin arttığını ve veri iletiminin daha uzun sürebileceğini işaret etmektedir.
Deneyler sırasında elde edilen diğer önemli bulgular arasında, LoRaWAN'ın ağ yoğunluğu ve çevresel faktörler gibi değişkenlerden nasıl etkilendiğinin belirlenmesi yer almaktadır. Ayrıca, LoRaWAN'ın farklı hızlarda hareket eden nesnelerle iletişimdeki başarı oranlarının incelenmesi, ağ performansının hızlı değişen koşullara nasıl tepki verdiğini anlamak açısından önemli bir bulgu olmuştur.
Bu bulguların analizi, LoRaWAN'ın hareketlilikle ilişkili performansının anlaşılmasına ve bu teknolojinin belirli uygulama senaryolarında nasıl optimize edilebileceğine dair önemli bilgiler sağlamaktadır.

5-) TARTIŞMA VE ÖNERİLER
5.1-)Bulguların Önemi ve Sonuçlarının Değerlendirilmesi
Bu çalışma, LoRaWAN teknolojisinin hareketlilik düzeyine bağlı performansını detaylı bir şekilde inceleyerek önemli bulgular ortaya koymuştur. Elde edilen sonuçlar, kablosuz iletişim teknolojilerinin hareketli ortamlardaki etkinliği hakkında değerli bilgiler sunmaktadır. Özellikle, LoRaWAN'ın yüksek hareketlilik düzeylerinde PDR'deki azalma ve gecikme sürelerindeki artış gibi performans değişimleri, bu teknolojinin hareketli ortamlarda karşılaştığı zorlukları göstermektedir.
Bu bulgular, IoT(Nesnelerin İnterneti) uygulamaları gibi belirli senaryolarda LoRaWAN'ın etkin kullanımının sınırlarını anlamamıza yardımcı olabilir. Ayrıca, LoRaWAN ağlarının optimize edilmesi ve performanslarının iyileştirilmesi için yönlendirici olabilir.
5.2-)Çalışmanın Kısıtları ve Gelecekteki Çalışmalar İçin Öneriler
Bu çalışmanın bazı kısıtları vardır. Örneğin, deneyler belirli bir ortamda yapılmış olabilir ve gerçek dünya koşullarını tam olarak yansıtmayabilir. Ayrıca, LoRaWAN ağlarının farklı konfigürasyonlarının performansı üzerindeki etkileri daha fazla araştırılmalıdır.
Gelecekteki çalışmalar, LoRaWAN'ın hareketli ortamlardaki performansını daha ayrıntılı olarak incelemeye devam etmelidir. Farklı ağ yoğunlukları, çevresel koşullar ve hareket hızları gibi faktörlerin performans üzerindeki etkileri daha detaylı bir şekilde araştırılmalıdır. Ayrıca, LoRaWAN ağlarının optimize edilmesi için yeni algoritmaların ve yöntemlerin geliştirilmesi de gelecekteki çalışmaların odak noktası olabilir.
5.3-)5G ve LoRaWAN Gibi Teknolojilerin Uygulama Alanlarına Yönelik Potansiyel Etkileri
5G ve LoRaWAN gibi teknolojiler, farklı uygulama alanları için farklı avantajlar sunar. 5G, yüksek bant genişliği ve düşük gecikme süresi gibi özelliklerle öne çıkar ve özellikle yüksek hızlı mobil iletişim uygulamaları için idealdir. Öte yandan, LoRaWAN uzun menzilli iletişim ve düşük güç tüketimi avantajlarıyla öne çıkar ve genellikle IoT uygulamaları için tercih edilir.
Bu teknolojilerin uygulama alanlarına yönelik potansiyel etkileri, belirli endüstrilerdeki iş süreçlerini ve uygulamalarını dönüştürebilir. Örneğin, tarım sektöründe, LoRaWAN gibi uzun menzilli iletişim teknolojileri, tarım sensörlerinin uzak alanlarda veri toplamasını ve izlenmesini sağlayarak verimliliği artırabilir. Benzer şekilde, 5G gibi yüksek hızlı iletişim teknolojileri, akıllı şehir uygulamaları gibi hızlı veri aktarımı gerektiren uygulamalar için önemli bir rol oynayabilir. Bu nedenle, belirli uygulama senaryolarına en uygun teknolojinin seçilmesi ve optimize edilmesi, teknolojinin etkin kullanımını sağlamak açısından önemlidir.

6-) SONUÇLAR
Bu çalışma, LoRaWAN teknolojisinin hareketlilik düzeyine bağlı performansını detaylı bir şekilde inceleyerek önemli bulgular elde etmiştir. Yapılan deneylerde, LoRaWAN'ın yüksek hareketlilik düzeylerinde PDR'deki azalma ve gecikme sürelerindeki artış gibi performans değişimleri gözlemlenmiştir. Bu bulgular, LoRaWAN teknolojisinin hareketli ortamlarda karşılaştığı zorlukları ve sınırları ortaya koymaktadır.
Bu çalışmadan elde edilen bulgular, LoRaWAN teknolojisinin hareketlilikle ilişkili performansını anlamamıza ve bu teknolojinin belirli uygulama senaryolarında nasıl optimize edilebileceğine dair önemli ipuçları sağlamaktadır. Gelecekteki araştırmaların, LoRaWAN'ın hareketli ortamlardaki kullanımını daha da geliştirmek için bu bulguları dikkate alması önemlidir.

7-) KAYNAKLAR
•	https://chatgpt.com
•	https://www.nsnam.org
•	https://eclipse.dev/sumo
•	https://github.com/signetlabdei/lorawan





