## IoT

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
Mode = 냉방,난방,제습중에 선택 <br>
MaxTemperature = 최고온도 <br>
MinTemperature = 최저온도 <br>
MaxHumidity = 최고습도 <br>
MinHumidity = 최저습도 <br>

#### Arduino -> Firebase 
Temperature = 지금 온도 <br>
Humidity = 지금 습도 <br>
