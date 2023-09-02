바## IoT

### 재료
WeMos D1 R1 <br>
서보모터 3개 <br>
온습도센서 1개 <br>
외부전원 <br>

### 수현
온습도를 측정하고 Firebase에 보냄 <br>
그러면 아두이노에서 읽어와서 에어컨을 끄고 키고 함 <br>
난방 냉방 제습조절이 가능하고 <br>
바람세기도 조절가능함 <br>


### DB
#### 웹 -> Firebase정보
Mode = 냉방,난방,제습중에 선택 (영어 -> Int) <br>
0은 냉방, 1은 난방, 2는 제습임 <br>
MaxTemperature = 최고온도 Float <br> 
웹에서 냉방 또는 난방을 선택했을때에 입력받는값 <br>
MinTemperature = 최저온도 Float <br>
웹에서 냉방 또는 난방을 선택했을때에 입력받는값 <br>
MaxHumidity = 최고습도 Float <br>
웹에서 제습을 선택했을때에 입력받는값 <br>
MinHumidity = 최저습도 Float <br>
웹에서 제습을 선택했을때에 입력받는값 <br>

#### Arduino -> Firebase 
Temperature = 지금 온도 Float <br>
Humidity = 지금 습도 Float <br>

내가 온도,습도입력방식은  <br>
![image](https://github.com/BSSM-Ctrl/Project/assets/128461452/679afe6f-0b07-4181-8173-fc0b766207c4)
이런 UI를 원한다. <br>
그런데 달라진다면 지금온도,습도는 넣고 바형식(?) 스크롤형식(?) 같은거로 하고싶음 이건 나중에 사진찾음 <br>
