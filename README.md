# Project Snake Game
<a name="top"><a>
## Mục lục

[Thông tin nhóm](#info)\
[Đề tài](#topic)\
[Mô tả project](#project)\
&nbsp;&nbsp;&nbsp; [Công nghệ sử dụng](#use)\
&nbsp;&nbsp;&nbsp; [Tính năng chính](#main-feature)\
[Demo](#demo)

## Thông tin nhóm <a name="info"></a>

Lớp: **SS004.M13** \
Tên nhóm: **3PGT** \
Thành viên:
| STT  | Tên                | MSSV      | Ghi chú     |
|:-----|:-------------------|:----------|:------------|
|  1   |   Trần Ngọc Tiến   | 20520808  |  Trưởng nhóm|
|  2   |  Nguyễn Tấn Giang  | 20521261  |             |
|  3   |  Lê Hoàng Phúc     | 20521763  |             |
|  4   |    Vũ Thiên Phú    | 20521758  |             |
|  5   | Nguyễn Hoàng Phúc  | 20521768  |             |

[Lên đầu trang](#top)
## Đề tài <a name="topic"></a>

Xây dựng game con rắn bằng ngôn ngữ C++

## Mô tả Project <a name="project"></a>

### Công nghệ sử dụng <a name="use"></a>

- Ngôn ngữ: C++
- IDE: DevC++ 

[Lên đầu trang](#top)
### Tính năng chính <a name="main-feature"></a>

– Khi mở chương trình bạn sẽ thấy một cửa sổ mới được mở lên trong đó có các mục như NewGame , HighScore , QuitGame, About :\
∗ NewGame để bắt đầu 1 game mới\
∗ HighScore để xem bảng xếp hạng của 5 người chơi có điểm số cao nhất\
∗ QuitGame để thoát khỏi chương trinh\
∗ About là thông tin về chương trinh.\
– Bạn sử dụng con trỏ chuột và click vào mục bạn muốn chọn. Riêng đối với NewGame thì bọn sẽ chọn 1 trong 2 chế độ chơi classic hoặc modern và với mỗi chế độ chơi thì có 5 cấp độ, với độ khó tăng dần từ 1 đến năm. Với 2 mục About và HighScore thì để trở về menu chinh bạn chỉ cần click chuột ở nới bất kỳ trong cửa sổ.\
  
• Hướng dẫn cách điều khiển\
– Về cơ bản thì cách điều khiển rắn của SnakeGame hoàn toan giống với cách điều khiển trong quá khứ là sử dụng các phím mũi tên để chuyển hướng.\
– Lưu ý là bạn chỉ có thể chuyển hướng từ phương ngang sang phương dọc và ngược lại.\
– Lúc đang chơi nếu muốn tạm dừng bạn sẽ nhấn phím space và nhấn phim esc để kết thúc game ngay lập tức.\
– Sau khi kết thức trò chơi bạn sẽ chờ một khoảng thời gian ngắn rồi nhập tên của minh và nhấn enter( tên không được có dấu cách). Nếu điểm số của bạn nằm trong 5 người cao điểm nhất thì sẽ được lưu trữ lại.\
• Hướng dẫn về lối chơi\
– Về cơ bản thì cả hương chế độ classic và modern có cách chơi khá giống nhau, chỉ khác nhau ở một vài điểm nhỏ.\
– Với chế độ classic:\
∗ Bạn sẽ hóa thân thành một chú rắn và sử dụng kỹ năng điều khiển một cách khéo léo để ăn được thức ăn.\
∗ Sau mỗi lần ăn được cơ thể của chú rắn sẽ tăng lên 1 đốt và điểm số của bạn tất nhiên cũng sẽ tăng lên\
∗ Nếu Rắn đi ra ngoài mép tường – cho rắn xuất hiện lại ở phía bên kia.\
∗ Bạn sẽ thua khi ăn phải thân minh.\
– Với chế độ modern:\
∗ Về cơ bản thì lối chơi giống classic bạn sẽ điều khiển chú rắn ăn thức ăn nhiều nhất có thể nhưng sẽ tăng thêm độ khó nữa là bạn không thể đi xuyên tường, trò chơi sẽ kết thúc khi bạn va vào tường hoặc tự ăn chính bản thân\

### Cấu trúc

#### Cấu trúc sử dụng cho các đối tượng:
• Tổng quát hóa các đối tượng\
– Con rắn săn mồi của chúng ta sẽ là một chuỗi các hình tròn nhỏ (các đốt của con rắn) nối lại với nhau (số hình tròn nhỏ chính là độ dài của con rắn). Khởi tạo trò chơi, Ta đặt độ dài ban đầu của nó là 3. Trong quá trình trò chơi diễn ra, ta phải lưu vết được tọa độ và bổ sung thêm số lượng các hình tròn đó.\
– Tại mỗi bước dịch chuyển của rắn, mỗi đốt thân sẽ di chuyển đi 1 đơn vị độ dài bằng nhau. Ta chỉ cần nắm bắt đốt thân đầu tiên (đầu của rắn) tiến lên theo hướng di chuyển, các đốt thân phía sau di chuyển đến vị trí cũ của đốt thân phía trước nó.\
– Thức ăn của gắn được coi là 1 hình tròn tương tự như một đốt thân của rắn.Tại mỗi thời điểm vị trị của thức ăn là ngẫu nhiên.\
• Chuyển đối tượng sang ngôn ngữ lập trình:\
– Một con rắn sẽ là 1 mảng các đối tượng Point tương ứng với các đốt của rắn. Tại mỗi đốt, cặp tọa độ (x,y) sẽ lưu vị trí đốt hiện tại và cặp tọa độ (x0,y0) sẽ lưu ví trí trước đó của đốt hiện tại để các đốt sau đó của con rắn có thể sử dụng.\
– Mỗi đối tượng thức ăn sẽ là 1 đối tượng Point. Ta chỉ cần sử dụng cặp biến (x, y) để lưu 1 đối tượng thức ăn. Tại một thời điểm trên màn hình chỉ có 1 thức ăn, và thức ăn đó xuất hiện ở 1 vị trí ngẫu nhiên bất kỳ.\
– Để rắn di chuyển được trên màn hình thì ta cần thêm một biến lưu hướng đi của nó. Ta tận dụng đối tượng Point để xác định hướng theo tọa độ (x,y). Ví dụ nếu rắn đang di chuyển theo hướng trái sang phải, như vậy đối tượng direction của ta sẽ là (10, 0) tức là tọa độ x sẽ tăng thêm 10 đơn vị và tọa độ y không đổi. Để thay đổi hướng đi ta chỉ cần thay đổi giá trị (x, y) của đối tượng direction. Khoảng cách mỗi lần di chuyển được ta định nghĩa bởi hằng số DIRECTION.\
• Cấu trúc Point gồm 4 thành phần : (x, y) lưu vị trị hiện tại, (x0,y0) lưu vị trị trươc đó nếu là 1 đốt của rắn.\
#### Hiển thị các đối tượng ra màn hình:
Trước hết ta sẽ viết các hàm khởi tạo giá trị và xuất hình ảnh Rắn, thức ăn , tường, tiêu đề ra màn hình thì ta cần viết các hàm sau :\
• void initGame(): để khởi tạo giá trị cho rắn (số lượng, tạo độ), Thức ăn(tọa độ),hướng di chuyển ban đầu, hình ảnh background cho các đối tượng cố định. Đơn giản chỉ là gán các giá trị cho các đối tượng và hiện thị hình ảnh background bằng các hàm đồ họa có sẵn trong thư viện như: outtextxy, settextstyle, setcolor,. . .\
• void drawPoint (int x,int y,int radius) đơn giản chỉ là vẽ một hình tròn ra màn hình với tâm có tọa độ (x,y) và bán kinh radius được truyền vào.\
• void drawSnake(): đơn giản chỉ gọi lại hàm drawPoint nhiều lần đề vẽ 12các đốt của rắn vói tọa độ tâm được truyền vào là tọa độ các đốt của rắn.\
• void drawFood(): Tương tự như drawSnake cũng là gọi lại hàm drawPoint với tọa độ truyền vào là tọa độ của thức ăn.\
• void drawGame(): chỉ đơn giản là gọi lại 2 hàm drawSnake và drawFood.\
• void showText(int x,int y,char *str): sẽ hiện thị ra màn hình chuỗi str tại vị trị (x,y) với màu sắc thay đổi liên tục sau một khoảng thời gian(sử dụng hàm delay).\
• void showTextBackground(int x,int y,char *str,int color) tương tự như hàm showText nhưng có thêm màu sắc của background xung quan là cố định được truyền vào qua tham số color.
#### Viết các hàm xây dựng tinh logic game.
Ở đây ta sẽ tiến hành xây dựng logic cho game như: dư chuyển, GameOver,...\
• void changeDirecton (int x): để thay đổi hướng đi ta chỉ cần thay đổi các giá trị (x,y) của biến direction dựa vào x và hướng di chuyển hiện tại. Với x ASCII của phím được nhập bởi bản phím ( x=72 đi lên ; x=80 hướng xuống; x=77 sang phải ; x=75 sang trái). Giá trị (x,y) của direction chỉ thay đổi khi có sự thay đổi về phương di chuyển nghĩa là : đang di chuyển theo phương ngang sau đó chuyển sang phương dọc và ngược lại.\
• void classic(): chỉ đơn giản thay đổi tọa độ các đốt của rắn .Nếu là đốt thân rắn thì tọa độ mới bằng tọa độ cũ điểm đốt đằng trước nó. Nếu là đầu rắn thì chỉ đơn giản là cộng tọa độ đốt đầu rắn với tọa độ của hướng di chuyển direction. Nếu đầu rắn đụng tượng thì ta không cộng với tọa độ direction mà thay bằng tọa độ của bức tường đối diện. Nếu đầu rắn trùng với thức ăn thì (tức là rắn đã ăn được thức ăn) thì ta tăng độ dài cho rắn và thay đổi vị trí mới cho thức ăn.\
• void modern(): hàm này tương như hàm classic nhưng khi đầu rắn đụng tường thay vì đi xuyên qua thì ta sẽ thêm điều kiện này là kết thúc trò chơi.\
• void mainLoop (void (*xxx)()) : đây là vòng lập chính cho 1 ván game tham số truyền vào của hàm này là 1 trong 2 hàm classic hoặc modern ở trên, và hàm này sẽ bắt mã acii các phím được nhập từ bàn phím ở bằng hàm kbnit () và getch() được cung cấp sẵn để thay điển hướng (direction) bằng cách truyền tham số vào hàm changeDirection(int x), tạm dừng hoăc kết thúc game.\
• bool checkPoint () : để đảm bảo vị trí mới của thức ăn không trùng với vị trí của rắn.\
#### Xây dựng các tiện ích cho chương trình:
Ở các bước trên ta đã hoàn thành cách điều khiển, di chuyển rắn, logic của game. Bây giờ ta sẽ viết thêm các tính năng như lưu điểm, menu, UI,. . .\
• Xây dụng các tiện ích:\
– Để lưu lại điểm của người chơi ta sẽ tạo cấu trúc highScore gồm 2 thành phần: name là tên người chơi , score là điểm của người chơi đó.\
– Ta cần tạo 1 file highscore.txt để lưu lại điểm số.\
– showHighScore () : ta sẽ hiển thị ra màn hình thông tin 5 người chơi có số điểm cao nhất được được lưu vào file highscore.txt .Nếu file highscore.txt rỗng thì mặc định tên của 5 người chơi đều bằng player và score=0.\
– bool isEmpty() hàm này sẽ giúp ta kiểm tra xem file highscore.txt có rỗng không.\
– void initScore() sẽ gọi lại hàm isEmpty xem file highscore.txt có rỗng rỗng không bằng cách sử dụng hàm isEmpty().Nếu rông thì khởi tạo tên của 5 người chơi đều là Player và score=0.\
– void getHighScore () : cập nhật lại danh sách 5 thành viên điểm cao vào file highscore.txt.\
– void checkHighScore(int score) hàm này sẽ giúp bạn nhập tên người chơi sau khi kết thúc kiểm tra xem số điểm của bạn đạt được có thuộc top 5 người đứng đầu không. Nếu có thì sẽ gọi hàm getHighScore để lưu dữ liệu của bạn vào file highscore.txt.\
• Xây dựng UI:\
– Để tạo thiện cảm với người dùng lúc mở chương trình ta sẽ tạo một màn hình tải game từ 0\
– Hàm run():\
∗ Đây là hàm chạy cho toàn bộ chương trinh, nó sẽ sử dụng các hàm đã viết ở trên.\
∗ Đầu tiên sẽ gọi hàm loadingScreen để tạo hiệu ứng tải load game.\
∗ Sủ dụng các hàm showTextBackground, setbkcolor, ShowText, . . . để hiển thị ra màn hình tại các vị trí cụ thể. Sử dụng ismouseclick bắt bắt tình huống click chuột, mousex là tọa độ x của con trỏ chuột, mousey là tọa đọ trục Oy của con trỏ chuột. Kết hợp với các lệnh điều kiện ràng buộc vị trí click chuột để gọi các hàm.\
∗ Để truyền âm thanh vào ta dùng hàm PlaySound(TEXT(“x”)) với x là đường dẫn vào file âm thanh.\
  
## Demo <a name="demo"></a>
  
https://user-images.githubusercontent.com/94039133/145713394-9964c460-e781-4b0e-a3dc-83318fe8d3b4.mp4


https://user-images.githubusercontent.com/94039133/145713396-726d1f95-6fd0-44e1-bd2d-e4de6cb974de.mp4


[Lên đầu trang](#top)
