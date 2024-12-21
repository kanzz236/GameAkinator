#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <memory>


#pragma execution_character_set("utf-8")


// Định nghĩa cấu trúc Node cho cây nhị phân
struct Node {
    std::string question;
    std::string imagePath;
    std::unique_ptr<Node> yes = nullptr;
    std::unique_ptr<Node> no = nullptr;

    Node(const std::string& q, const std::string& img = "") : question(q), imagePath(img) {}
};

// Hàm tạo cây nhị phân
std::unique_ptr<Node> createTree() {
    auto root = std::make_unique<Node>("Người này là nam ?");
    root->yes = std::make_unique<Node>("Người này là rapper?");
    root->no = std::make_unique<Node>("Người này rapper ?");

    // Nhánh yes -> rap
    root->yes->yes = std::make_unique<Node>("Người này có xuất hiện trong Rap Việt ?");
    root->yes->no = std::make_unique<Node>("Người này có tham gia Anh Trai Say Hi ?");

    root->yes->yes->yes = std::make_unique<Node>("Người này có thuộc hàng HLV ?");
    root->yes->yes->yes->yes = std::make_unique<Node>("Người này có tham gia Anh Trai Say Hi ?");
    root->yes->yes->yes->yes->yes = std::make_unique<Node>("Thuộc tổ đội Gerdnang ?");
    root->yes->yes->yes->yes->yes->yes = std::make_unique<Node>("Hieuthuhai");
    root->yes->yes->yes->yes->yes->no = std::make_unique<Node>("Là giám đốc âm nhạc/Producer ?");
    root->yes->yes->yes->yes->yes->no->yes = std::make_unique<Node>("JustaTee");
    root->yes->yes->yes->yes->yes->no->no = std::make_unique<Node>("1 ai đó tôi không biết");
    root->yes->yes->yes->yes->no = std::make_unique<Node>("Người này có trong SpaceSpeakers ?");
    root->yes->yes->yes->yes->no->yes = std::make_unique<Node>("Bigcityboi?");
    root->yes->yes->yes->yes->no->yes->yes = std::make_unique<Node>("Binz");
    root->yes->yes->yes->yes->no->yes->no = std::make_unique<Node>("Có bài Nến và hoa?");
    root->yes->yes->yes->yes->no->yes->no->yes = std::make_unique<Node>("Rhymastic");
    root->yes->yes->yes->yes->no->yes->no->no = std::make_unique<Node>("1 ai đó tôi không biết");


    root->yes->yes->yes->yes->no->no = std::make_unique<Node>("Đã lập gia đình ?");
    root->yes->yes->yes->yes->no->no->yes = std::make_unique<Node>("Là giám đốc âm nhạc?");
    root->yes->yes->yes->yes->no->no->yes->yes = std::make_unique<Node>("JustaTee");
    root->yes->yes->yes->yes->no->no->yes->no = std::make_unique<Node>("Có bài Mượn rượu tỏ tình?");
    root->yes->yes->yes->yes->no->no->yes->no->yes = std::make_unique<Node>("BigDaddy");
    root->yes->yes->yes->yes->no->no->yes->no->no = std::make_unique<Node>("1 ai đó tôi không biết");

    root->yes->yes->yes->yes->no->no->no = std::make_unique<Node>("Người miền Bắc?");
    root->yes->yes->yes->yes->no->no->no->yes = std::make_unique<Node>("Làm nhạc flex, ăn chơi?");
    root->yes->yes->yes->yes->no->no->no->yes->yes = std::make_unique<Node>("Andree Right Hand");
    root->yes->yes->yes->yes->no->no->no->yes->no = std::make_unique<Node>("1 ai đó tôi không biết");
    root->yes->yes->yes->yes->no->no->no->no = std::make_unique<Node>("Boy Mỹ con?");
    root->yes->yes->yes->yes->no->no->no->no->yes = std::make_unique<Node>("Bray");
    root->yes->yes->yes->yes->no->no->no->no->no = std::make_unique<Node>("Có bài Khu Tao Sống?");
    root->yes->yes->yes->yes->no->no->no->no->no->yes = std::make_unique<Node>("Chúa tể vần đơn?");
    root->yes->yes->yes->yes->no->no->no->no->no->yes->yes = std::make_unique<Node>("Wowy");
    root->yes->yes->yes->yes->no->no->no->no->no->yes->no = std::make_unique<Node>("Karik");
    root->yes->yes->yes->yes->no->no->no->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");






    root->yes->yes->yes->no = std::make_unique<Node>("Người này có tham gia Anh Trai Say Hi ?");
    root->yes->yes->yes->no->yes = std::make_unique<Node>("Có trong Gerdnang không?");
    root->yes->yes->yes->no->yes->yes = std::make_unique<Node>("HurryKng");
    root->yes->yes->yes->no->yes->no = std::make_unique<Node>("Lại là DGHouse?");
    root->yes->yes->yes->no->yes->no->yes = std::make_unique<Node>("Rhyder");
    root->yes->yes->yes->no->yes->no->no = std::make_unique<Node>("Captainboy bay tới đây?");
    root->yes->yes->yes->no->yes->no->no->yes = std::make_unique<Node>("Captain");
    root->yes->yes->yes->no->yes->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");

    root->yes->yes->yes->no->no = std::make_unique<Node>("Có ra album hot trong 2-3 năm gần đây?");
    root->yes->yes->yes->no->no->yes = std::make_unique<Node>("Có phải người miền Bắc?");
    root->yes->yes->yes->no->no->yes->yes = std::make_unique<Node>("Album 99%?");
    root->yes->yes->yes->no->no->yes->yes->yes = std::make_unique<Node>("MCK");
    root->yes->yes->yes->no->no->yes->yes->no = std::make_unique<Node>("Hoàng tử Long Biên?");
    root->yes->yes->yes->no->no->yes->yes->no->yes = std::make_unique<Node>("24kRight");
    root->yes->yes->yes->no->no->yes->yes->no->no = std::make_unique<Node>("Bạn từng thân của MCK?");
    root->yes->yes->yes->no->no->yes->yes->no->no->yes = std::make_unique<Node>("Wxrdie");
    root->yes->yes->yes->no->no->yes->yes->no->no->no = std::make_unique<Node>("Tune tẩm đá?");
    root->yes->yes->yes->no->no->yes->yes->no->no->no->yes = std::make_unique<Node>("Mikelodic");
    root->yes->yes->yes->no->no->yes->yes->no->no->no->no = std::make_unique<Node>("Có liên quan đến Min?");
    root->yes->yes->yes->no->no->yes->yes->no->no->no->no->yes = std::make_unique<Node>("16typh");
    root->yes->yes->yes->no->no->yes->yes->no->no->no->no->no = std::make_unique<Node>("Coldzy");

    root->yes->yes->yes->no->no->yes->no = std::make_unique<Node>("Album Đánh đổi?");
    root->yes->yes->yes->no->no->yes->no->yes = std::make_unique<Node>("Obito");
    root->yes->yes->yes->no->no->yes->no->no = std::make_unique<Node>("Có bài Phi Hành Gia?");
    root->yes->yes->yes->no->no->yes->no->no->yes = std::make_unique<Node>("Lil Wuyn");
    root->yes->yes->yes->no->no->yes->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");

    root->yes->yes->yes->no->no->no = std::make_unique<Node>("Người này thuộc LGBT ?");
    root->yes->yes->yes->no->no->no->yes = std::make_unique<Node>("Pháp Kiều");
    root->yes->yes->yes->no->no->no->no = std::make_unique<Node>("Có vào đến vòng Chung kết Rap Việt?");
    root->yes->yes->yes->no->no->no->no->yes = std::make_unique<Node>("Là quán quân hoặc á quân?");
    root->yes->yes->yes->no->no->no->no->yes->yes = std::make_unique<Node>("Đã thi Rap Việt ít nhất 2 lần?");
    root->yes->yes->yes->no->no->no->no->yes->yes->yes = std::make_unique<Node>("Gill");
    root->yes->yes->yes->no->no->no->no->yes->yes->no = std::make_unique<Node>("Người miền núi chất?");
    root->yes->yes->yes->no->no->no->no->yes->yes->no->yes = std::make_unique<Node>("Double2T");
    root->yes->yes->yes->no->no->no->no->yes->yes->no->no = std::make_unique<Node>("Thuộc đội HLV Karik?");
    root->yes->yes->yes->no->no->no->no->yes->yes->no->no->yes = std::make_unique<Node>("Tổ đội OTĐ?");
    root->yes->yes->yes->no->no->no->no->yes->yes->no->no->yes->yes = std::make_unique<Node>("Seachains");
    root->yes->yes->yes->no->no->no->no->yes->yes->no->no->yes->no = std::make_unique<Node>("Gducky");
    root->yes->yes->yes->no->no->no->no->yes->yes->no->no->no = std::make_unique<Node>("Thuộc đội HLV Wowy");
    root->yes->yes->yes->no->no->no->no->yes->yes->no->no->no->yes = std::make_unique<Node>("Xăm kín người?");
    root->yes->yes->yes->no->no->no->no->yes->yes->no->no->no->yes->yes = std::make_unique<Node>("Dế Choắt");
    root->yes->yes->yes->no->no->no->no->yes->yes->no->no->no->yes->no = std::make_unique<Node>("Blacka");
    root->yes->yes->yes->no->no->no->no->yes->yes->no->no->no->no = std::make_unique<Node>("Thuộc tổ đội Hustlang?");
    root->yes->yes->yes->no->no->no->no->yes->yes->no->no->no->no->yes = std::make_unique<Node>("Robber");
    root->yes->yes->yes->no->no->no->no->yes->yes->no->no->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");

    root->yes->yes->yes->no->no->no->no->yes->no = std::make_unique<Node>("Có bài WrongTimes?");
    root->yes->yes->yes->no->no->no->no->yes->no->yes = std::make_unique<Node>("Dangrangto");
    root->yes->yes->yes->no->no->no->no->yes->no->no = std::make_unique<Node>("Thuộc tổ đội OTĐ?");
    root->yes->yes->yes->no->no->no->no->yes->no->no->yes = std::make_unique<Node>("Có bài Bắc Kim Thang?");
    root->yes->yes->yes->no->no->no->no->yes->no->no->yes->yes = std::make_unique<Node>("Ricky Star");
    root->yes->yes->yes->no->no->no->no->yes->no->no->yes->no = std::make_unique<Node>("Lăng LD");
    root->yes->yes->yes->no->no->no->no->yes->no->no->no = std::make_unique<Node>("Thuộc tổ đội Hustlang?");
    root->yes->yes->yes->no->no->no->no->yes->no->no->no->yes = std::make_unique<Node>("Thuyền trưởng?");
    root->yes->yes->yes->no->no->no->no->yes->no->no->no->yes->yes = std::make_unique<Node>("Robber");
    root->yes->yes->yes->no->no->no->no->yes->no->no->no->yes->no = std::make_unique<Node>("Thể loại melodic rap?");
    root->yes->yes->yes->no->no->no->no->yes->no->no->no->yes->no->yes = std::make_unique<Node>("VSoul");
    root->yes->yes->yes->no->no->no->no->yes->no->no->no->yes->no->no = std::make_unique<Node>("Thành Draw");

    root->yes->yes->yes->no->no->no->no->yes->no->no->no->no = std::make_unique<Node>("Đã thi Rap Việt ít nhất 2 lần?");
    root->yes->yes->yes->no->no->no->no->yes->no->no->no->no->yes = std::make_unique<Node>("Có liên quan đến Pháo?");
    root->yes->yes->yes->no->no->no->no->yes->no->no->no->no->yes->yes = std::make_unique<Node>("Tez");
    root->yes->yes->yes->no->no->no->no->yes->no->no->no->no->yes->no = std::make_unique<Node>("Dlow");
    root->yes->yes->yes->no->no->no->no->yes->no->no->no->no->no = std::make_unique<Node>("Tune tẩm đá?");
    root->yes->yes->yes->no->no->no->no->yes->no->no->no->no->no->yes = std::make_unique<Node>("Mikelodic");
    root->yes->yes->yes->no->no->no->no->yes->no->no->no->no->no->no = std::make_unique<Node>("Thuộc tổ đội Bạn có tài mà?");
    root->yes->yes->yes->no->no->no->no->yes->no->no->no->no->no->no->yes = std::make_unique<Node>("Huỳnh Công Hiếu");
    root->yes->yes->yes->no->no->no->no->yes->no->no->no->no->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");





    root->yes->yes->yes->no->no->no->no->no = std::make_unique<Node>("Tham gia Rap Việt ít nhất 2 mùa?");
    root->yes->yes->yes->no->no->no->no->no->yes = std::make_unique<Node>("Mới ra 1 album gần đây?");
    root->yes->yes->yes->no->no->no->no->no->yes->yes = std::make_unique<Node>("Coldzy");
    root->yes->yes->yes->no->no->no->no->no->yes->no = std::make_unique<Node>("Có liên quan đến Min?");
    root->yes->yes->yes->no->no->no->no->no->yes->no->yes = std::make_unique<Node>("16Typh");
    root->yes->yes->yes->no->no->no->no->no->yes->no->no = std::make_unique<Node>("Yuno Bigboy");
    root->yes->yes->yes->no->no->no->no->no->no = std::make_unique<Node>("Mới tham gia Rap Việt mùa 4?");
    root->yes->yes->yes->no->no->no->no->no->no->yes = std::make_unique<Node>("Có bài Trương Đình Hoàng?");
    root->yes->yes->yes->no->no->no->no->no->no->yes->yes = std::make_unique<Node>("Lil Van");
    root->yes->yes->yes->no->no->no->no->no->no->yes->no = std::make_unique<Node>("Tiểu Rùa cầm phi tiêu?");
    root->yes->yes->yes->no->no->no->no->no->no->yes->no->yes = std::make_unique<Node>("Left Hand");
    root->yes->yes->yes->no->no->no->no->no->no->yes->no->no = std::make_unique<Node>("1 ai đó tôi không biết");

    root->yes->yes->yes->no->no->no->no->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");


    root->yes->yes->no = std::make_unique<Node>("Là người miền Bắc không?");
    root->yes->yes->no->yes = std::make_unique<Node>("Nhà hóa học Đống Đa??");
    root->yes->yes->no->yes->yes = std::make_unique<Node>("LowG");
    root->yes->yes->no->yes->no = std::make_unique<Node>("Có bài Vinflow?");
    root->yes->yes->no->yes->no->yes = std::make_unique<Node>("Wxrdie");

    root->yes->yes->no->yes->no->no = std::make_unique<Node>("Là 1 rapper kì cựu(hoạt động từ 2010)?");
    root->yes->yes->no->yes->no->no->yes = std::make_unique<Node>("Có bài Hồng Lâu Mộng?");
    root->yes->yes->no->yes->no->no->yes->yes = std::make_unique<Node>("Hưng Cao");
    root->yes->yes->no->yes->no->no->yes->no = std::make_unique<Node>("Có bài Lớn rồi?");
    root->yes->yes->no->yes->no->no->yes->no->yes = std::make_unique<Node>("DSK");
    root->yes->yes->no->yes->no->no->yes->no->no = std::make_unique<Node>("Mang Tiền Về Cho Mẹ?");
    root->yes->yes->no->yes->no->no->yes->no->no->yes = std::make_unique<Node>("Đen Vâu");
    root->yes->yes->no->yes->no->no->yes->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");



    root->yes->yes->no->yes->no->no->no = std::make_unique<Node>("Là học trò của Hưng Cao?");
    root->yes->yes->no->yes->no->no->no->yes = std::make_unique<Node>("Có mẹ bán bánh mì?");
    root->yes->yes->no->yes->no->no->no->yes->yes = std::make_unique<Node>("Phúc Du");
    root->yes->yes->no->yes->no->no->no->yes->no = std::make_unique<Node>("Đười ươi tóc trắng?");
    root->yes->yes->no->yes->no->no->no->yes->no->yes = std::make_unique<Node>("Richchoi");
    root->yes->yes->no->yes->no->no->no->yes->no->no = std::make_unique<Node>("King of Drill?");
    root->yes->yes->no->yes->no->no->no->yes->no->no->yes = std::make_unique<Node>("Hazel");
    root->yes->yes->no->yes->no->no->no->yes->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");


    root->yes->yes->no->yes->no->no->no->no = std::make_unique<Node>("Làm nhạc ăn chơi, flex?");
    root->yes->yes->no->yes->no->no->no->no->yes = std::make_unique<Node>("Có bài Ông bà già tao lo hết?");
    root->yes->yes->no->yes->no->no->no->no->no = std::make_unique<Node>("Làm nhạc chế?");
    root->yes->yes->no->yes->no->no->no->no->no->yes = std::make_unique<Node>("Gió?");
    root->yes->yes->no->yes->no->no->no->no->no->yes->yes = std::make_unique<Node>("Cậu Phát");
    root->yes->yes->no->yes->no->no->no->no->no->yes->no = std::make_unique<Node>("CCMK");
    root->yes->yes->no->yes->no->no->no->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");
    root->yes->yes->no->yes->no->no->no->no->yes->yes = std::make_unique<Node>("Bình Gold");
    root->yes->yes->no->yes->no->no->no->no->yes->no = std::make_unique<Node>("1 ai đó tôi không biết");


    root->yes->yes->no->no = std::make_unique<Node>("Có drama nổi tiếng 1 vài năm gần đây ?");
    root->yes->yes->no->no->yes = std::make_unique<Node>("Bỏ con?");
    root->yes->yes->no->no->yes->yes = std::make_unique<Node>("Jack 5 củ");
    root->yes->yes->no->no->yes->no = std::make_unique<Node>("Phát ngôn gây sốc?");
    root->yes->yes->no->no->yes->no->yes = std::make_unique<Node>("Negav");
    root->yes->yes->no->no->yes->no->no = std::make_unique<Node>("người ko trong dữ liệu");
    root->yes->yes->no->no->no = std::make_unique<Node>("Thích làm nhạc buồn ?");
    root->yes->yes->no->no->no->yes = std::make_unique<Node>("Có bài Blue Tequila?");
    root->yes->yes->no->no->no->yes->yes = std::make_unique<Node>("Táo");
    root->yes->yes->no->no->no->yes->no = std::make_unique<Node>("Có trong Gerdnang ?");
    root->yes->yes->no->no->no->yes->no->yes = std::make_unique<Node>("Hieuthuhai");
    root->yes->yes->no->no->no->yes->no->no = std::make_unique<Node>("Rap trong bài Chân Ái của Châu Đăng Khoa?");
    root->yes->yes->no->no->no->yes->no->no->yes = std::make_unique<Node>("Khói");
    root->yes->yes->no->no->no->yes->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");

    root->yes->yes->no->no->no->no = std::make_unique<Node>("Có trong Gerdnang ?");
    root->yes->yes->no->no->no->no->yes = std::make_unique<Node>("Hieuthuhai");
    root->yes->yes->no->no->no->no->no = std::make_unique<Node>("Nổi tiếng vì fastflow?");
    root->yes->yes->no->no->no->no->no->yes = std::make_unique<Node>("Datmaniac");
    root->yes->yes->no->no->no->no->no->no = std::make_unique<Node>("Viên ngọc ẩn của Việt rap?");
    root->yes->yes->no->no->no->no->no->no->yes = std::make_unique<Node>("Anh Phan");

    root->yes->yes->no->no->no->no->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");





    root->yes->no = std::make_unique<Node>("Người này có tham gia Anh Trai Say Hi ?");
    root->yes->no->yes = std::make_unique<Node>("Nghệ danh có từ tiếng Anh ?");
    root->yes->no->yes->yes = std::make_unique<Node>(" Người này có chất giọng đặc biệt ?");
    root->yes->no->yes->yes->yes = std::make_unique<Node>("Người này nổi tiếng bên Thái ?");
    root->yes->no->yes->yes->yes->yes = std::make_unique<Node>("Quang Hùng MasterD");
    root->yes->no->yes->yes->yes->no = std::make_unique<Node>("Có bài Ghen/Sau tất cả?");
    root->yes->no->yes->yes->yes->no->yes = std::make_unique<Node>("Erik");
    root->yes->no->yes->yes->yes->no->no = std::make_unique<Node>("Có bài Bông Hoa Đẹp Nhất?");
    root->yes->no->yes->yes->yes->no->no->yes = std::make_unique<Node>("Quân AP");
    root->yes->no->yes->yes->yes->no->no->no = std::make_unique<Node>("Tràn bộ nhớ?");
    root->yes->no->yes->yes->yes->no->no->no->yes = std::make_unique<Node>("Dương Domic");
    root->yes->no->yes->yes->yes->no->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");

    root->yes->no->yes->yes->no = std::make_unique<Node>("Người này có ra MV hot trong 1 tháng gần đây?");
    root->yes->no->yes->yes->no->yes = std::make_unique<Node>("Ngày đẹp trời để nói chia tay?");
    root->yes->no->yes->yes->no->yes->yes = std::make_unique<Node>("Lou Hoàng");
    root->yes->no->yes->yes->no->yes->no = std::make_unique<Node>("Có bài Tràn Bộ Nhớ?");
    root->yes->no->yes->yes->no->yes->no->yes = std::make_unique<Node>("Dương Domic");
    root->yes->no->yes->yes->no->yes->no->no = std::make_unique<Node>("1 ai đó tôi không biết");
    root->yes->no->yes->yes->no->no = std::make_unique<Node>("Có bài Bông Hoa Đẹp Nhất?");
    root->yes->no->yes->yes->no->no->yes = std::make_unique<Node>("Quân AP");
    root->yes->no->yes->yes->no->no->no = std::make_unique<Node>("Từng là thành viên của nhóm 365?");
    root->yes->no->yes->yes->no->no->no->yes = std::make_unique<Node>("Isaac");
    root->yes->no->yes->yes->no->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");















    root->yes->no->yes->no = std::make_unique<Node>("Người này có liên quan đến Lyly ?");
    root->yes->no->yes->no->yes = std::make_unique<Node>("Anh Tú");
    root->yes->no->yes->no->no = std::make_unique<Node>("Có bài Hết thương cạn nhớ?");
    root->yes->no->yes->no->no->yes = std::make_unique<Node>("Đức Phúc");
    root->yes->no->yes->no->no->no = std::make_unique<Node>("Người này có liên quan đến Pickleball?");
    root->yes->no->yes->no->no->no->yes = std::make_unique<Node>("Đỗ Phú Quí");
    root->yes->no->yes->no->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");





    root->yes->no->no = std::make_unique<Node>("Người này chủ yếu hát ballad, indie ?");
    root->yes->no->no->yes = std::make_unique<Node>("Nghệ danh người này có từ tiếng Anh ?");
    root->yes->no->no->yes->yes = std::make_unique<Node>("Có bài Phía sau 1 cô gái?");
    root->yes->no->no->yes->yes->yes = std::make_unique<Node>("Soobin Hoàng Sơn");
    root->yes->no->no->yes->yes->no = std::make_unique<Node>("Fandom tên Sky?");
    root->yes->no->no->yes->yes->no->yes = std::make_unique<Node>("Sơn Tùng MTP");
    root->yes->no->no->yes->yes->no->no = std::make_unique<Node>("Chạm khẽ tim anh 1 chút thôi?");
    root->yes->no->no->yes->yes->no->no->yes = std::make_unique<Node>("Noo Phước Thịnh");
    root->yes->no->no->yes->yes->no->no->no = std::make_unique<Node>("Là nhạc sĩ kiêm ca sĩ?");
    root->yes->no->no->yes->yes->no->no->no->yes = std::make_unique<Node>("Một bước yêu vạn dặm đau?");
    root->yes->no->no->yes->yes->no->no->no->yes->yes = std::make_unique<Node>("Mr Siro");
    root->yes->no->no->yes->yes->no->no->no->yes->no = std::make_unique<Node>("Có bài Suýt nữa thì?");
    root->yes->no->no->yes->yes->no->no->no->yes->no->yes = std::make_unique<Node>("Andiez");
    root->yes->no->no->yes->yes->no->no->no->yes->no->no = std::make_unique<Node>("1 ai đó tôi không biết");
    root->yes->no->no->yes->yes->no->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");

    root->yes->no->no->yes->no = std::make_unique<Node>("Nghệ danh người này có 1 từ ?");
    root->yes->no->no->yes->no->yes = std::make_unique<Node>("Có bài Bước qua nhau?");
    root->yes->no->no->yes->no->yes->yes = std::make_unique<Node>("Vũ");
    root->yes->no->no->yes->no->yes->no = std::make_unique<Node>("Thành viên của Ngọt Band?");
    root->yes->no->no->yes->no->yes->no->yes = std::make_unique<Node>("Thắng aka Vũ Đình Trọng Thắng");
    root->yes->no->no->yes->no->yes->no->no = std::make_unique<Node>("Liên quan đến tàu ToniButter");
    root->yes->no->no->yes->no->yes->no->no->yes = std::make_unique<Node>("Kiên aka Trịnh Trung Kiên");
    root->yes->no->no->yes->no->yes->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");

    root->yes->no->no->yes->no->no = std::make_unique<Node>("Nghệ danh có 3 từ?");
    root->yes->no->no->yes->no->no->yes = std::make_unique<Node>("Có bài Vợ người ta?");
    root->yes->no->no->yes->no->no->yes->yes = std::make_unique<Node>("Phan Mạnh Quỳnh");
    root->yes->no->no->yes->no->no->yes->no = std::make_unique<Node>("Tháng tư là lời nói dối của em?");
    root->yes->no->no->yes->no->no->yes->no->yes = std::make_unique<Node>("Hà Anh Tuấn");
    root->yes->no->no->yes->no->no->yes->no->no = std::make_unique<Node>("Sài Gòn đau lòng quá?");
    root->yes->no->no->yes->no->no->yes->no->no->yes = std::make_unique<Node>("Hứa Kim Tuyền");
    root->yes->no->no->yes->no->no->yes->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");


    root->yes->no->no->yes->no->no->no = std::make_unique<Node>("Có bài Nàng thơ?");
    root->yes->no->no->yes->no->no->no->yes = std::make_unique<Node>("Hoàng Dũng");
    root->yes->no->no->yes->no->no->no->no = std::make_unique<Node>("Một đêm say?");
    root->yes->no->no->yes->no->no->no->no->yes = std::make_unique<Node>("Thịnh Suy");
    root->yes->no->no->yes->no->no->no->no->no = std::make_unique<Node>("Có bài Điều anh biết?");
    root->yes->no->no->yes->no->no->no->no->no->yes = std::make_unique<Node>("Chi Dân");
    root->yes->no->no->yes->no->no->no->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");

    root->yes->no->no->no = std::make_unique<Node>("Nghệ danh người này có từ tiếng Anh ?");

    root->yes->no->no->no->yes = std::make_unique<Node>("Mới nổi 1 2 năm gần đây?");
    root->yes->no->no->no->yes->yes = std::make_unique<Node>("Có bài Bé ơi từ từ?");
    root->yes->no->no->no->yes->yes->yes = std::make_unique<Node>("Wren Evans");
    root->yes->no->no->no->yes->yes->no = std::make_unique<Node>("1 ai đó tôi không biết");
    root->yes->no->no->no->yes->no = std::make_unique<Node>("Fandom tên Sky");
    root->yes->no->no->no->yes->no->yes = std::make_unique<Node>("Sơn Tùng MTP");
    root->yes->no->no->no->yes->no->no = std::make_unique<Node>("Bỏ con?");
    root->yes->no->no->no->yes->no->no->yes = std::make_unique<Node>("Jack 5 củ");
    root->yes->no->no->no->yes->no->no->no = std::make_unique<Node>("Có tham gia ATVNCG?");
    root->yes->no->no->no->yes->no->no->no->yes = std::make_unique<Node>("Có bài Tết đong đầy?");
    root->yes->no->no->no->yes->no->no->no->yes->yes = std::make_unique<Node>("Kay Trần");
    root->yes->no->no->no->yes->no->no->no->yes->no = std::make_unique<Node>("Cựu thành viên 365band?");
    root->yes->no->no->no->yes->no->no->no->yes->no->yes = std::make_unique<Node>("Có bài Đây là 1 bài hát vui?");
    root->yes->no->no->no->yes->no->no->no->yes->no->yes->yes = std::make_unique<Node>("Jun Phạm");
    root->yes->no->no->no->yes->no->no->no->yes->no->yes->no = std::make_unique<Node>("ST Sơn Thạch");
    root->yes->no->no->no->yes->no->no->no->yes->no->no = std::make_unique<Node>("Có bài Anh Thanh Niên?");
    root->yes->no->no->no->yes->no->no->no->yes->no->no->yes = std::make_unique<Node>("HuyR");
    root->yes->no->no->no->yes->no->no->no->yes->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");

    root->yes->no->no->no->yes->no->no->no->no = std::make_unique<Node>("Có bài Chạm khẽ tim anh 1 chút thôi?");
    root->yes->no->no->no->yes->no->no->no->no->yes = std::make_unique<Node>("Noo Phước Thịnh");
    root->yes->no->no->no->yes->no->no->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");

    root->yes->no->no->no->no = std::make_unique<Node>("Mới nổi vài năm gần đây?");
    root->yes->no->no->no->no->yes = std::make_unique<Node>("Bên trên tầng lầu?");
    root->yes->no->no->no->no->yes->yes = std::make_unique<Node>("Tăng Duy Tân");
    root->yes->no->no->no->no->yes->no = std::make_unique<Node>("Tết này con sẽ về?");
    root->yes->no->no->no->no->yes->no->yes = std::make_unique<Node>("Bùi Công Nam");
    root->yes->no->no->no->no->yes->no->no = std::make_unique<Node>("1 ai đó tôi không biết");

    root->yes->no->no->no->no->no = std::make_unique<Node>("Có tham gia ATVNCG?");
    root->yes->no->no->no->no->no->yes = std::make_unique<Node>("Có giọng khàn đặc trưng?");
    root->yes->no->no->no->no->no->yes->yes = std::make_unique<Node>("Tuấn Hưng");
    root->yes->no->no->no->no->no->yes->no = std::make_unique<Node>("Thuộc thế hệ 7x?");
    root->yes->no->no->no->no->no->yes->no->yes = std::make_unique<Node>("Có bài Cơn Mưa Băng Giá?");
    root->yes->no->no->no->no->no->yes->no->yes->yes = std::make_unique<Node>("Bằng Kiều");
    root->yes->no->no->no->no->no->yes->no->yes->no = std::make_unique<Node>("Có bài Khúc hát mừng sinh nhật?");
    root->yes->no->no->no->no->no->yes->no->yes->no->yes = std::make_unique<Node>("Phan Đinh Tùng");
    root->yes->no->no->no->no->no->yes->no->yes->no->no = std::make_unique<Node>("1 ai đó tôi không biết");

    root->yes->no->no->no->no->no->no = std::make_unique<Node>("Mới ra nhạc gần đây?");
    root->yes->no->no->no->no->no->no->yes = std::make_unique<Node>("Có bài Sáng mắt chưa?");
    root->yes->no->no->no->no->no->no->yes->yes = std::make_unique<Node>("Trúc Nhân");
    root->yes->no->no->no->no->no->no->yes->no = std::make_unique<Node>("Có bài Ngày chưa giông bão?");
    root->yes->no->no->no->no->no->no->yes->no->yes = std::make_unique<Node>("Tùng Dương");
    root->yes->no->no->no->no->no->no->yes->no->no = std::make_unique<Node>("1 ai đó tôi không biết");

    root->yes->no->no->no->no->no->no->no = std::make_unique<Node>("Nghệ danh có 2 từ?");

    root->yes->no->no->no->no->no->no->no->yes = std::make_unique<Node>("Có bài Chiếc khăn gió ấm?");
    root->yes->no->no->no->no->no->no->no->yes->yes = std::make_unique<Node>("Khánh Phương");

    root->yes->no->no->no->no->no->no->no->yes->no = std::make_unique<Node>("Có bài Em khác hay anh khác?");
    root->yes->no->no->no->no->no->no->no->yes->no->yes = std::make_unique<Node>("Khắc Việt");
    root->yes->no->no->no->no->no->no->no->yes->no->no = std::make_unique<Node>("1 ai đó tôi không biết");
    root->yes->no->no->no->no->no->no->no->no = std::make_unique<Node>("Có bài Con bướm xuân?");
    root->yes->no->no->no->no->no->no->no->no->yes = std::make_unique<Node>("Hồ Quang Hiếu");
    root->yes->no->no->no->no->no->no->no->no->no = std::make_unique<Node>("Lâu đài tình ái?");
    root->yes->no->no->no->no->no->no->no->no->no->yes = std::make_unique<Node>("Đàm Vĩnh Hưng");
    root->yes->no->no->no->no->no->no->no->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");



    root->no->yes = std::make_unique<Node>("Có xuất hiện trong Rap Việt ?");
    root->no->yes->yes = std::make_unique<Node>("Có làm HLV không?");
    root->no->yes->yes->yes = std::make_unique<Node>("Suboi");
    root->no->yes->yes->no = std::make_unique<Node>("Album Ái?");
    root->no->yes->yes->no->yes = std::make_unique<Node>("Tlinh");
    root->no->yes->yes->no->no = std::make_unique<Node>("Liu Grace");

    root->no->yes->no = std::make_unique<Node>("Có bài Hai Phút Hơn?");
    root->no->yes->no->yes = std::make_unique<Node>("Pháo");
    root->no->yes->no->no = std::make_unique<Node>("1 ai đó tôi không biết");


    root->no->no = std::make_unique<Node>("Người này là nghệ sĩ trẻ (sinh cuối 9x đầu 2k)?");
    root->no->no->yes = std::make_unique<Node>("Nghệ danh thuần tiếng Việt ?");
    root->no->no->yes->yes = std::make_unique<Node>("Hát nhiều dòng nhạc dân gian ?");
    root->no->no->yes->yes->yes = std::make_unique<Node>("Album Cò lả?");
    root->no->no->yes->yes->yes->yes = std::make_unique<Node>("Phương Mỹ Chi");
    root->no->no->yes->yes->yes->no = std::make_unique<Node>("người ko trong dữ liệu");
    root->no->no->yes->yes->no = std::make_unique<Node>("Từng feat với Thắng Ngọt?");
    root->no->no->yes->yes->no->yes = std::make_unique<Node>("Vũ Thanh Vân");
    root->no->no->yes->yes->no->no = std::make_unique<Node>("1 ai đó tôi không biết");

    root->no->no->yes->no = std::make_unique<Node>("Từng feat với Bray?");
    root->no->no->yes->no->yes = std::make_unique<Node>("Có bài Anh nhà ở đâu thế?");
    root->no->no->yes->no->yes->yes = std::make_unique<Node>("Amee");
    root->no->no->yes->no->yes->no = std::make_unique<Node>("Có liên quan đến Châu Đăng Khoa?");
    root->no->no->yes->no->yes->no->yes = std::make_unique<Node>("Sofia");
    root->no->no->yes->no->yes->no->no = std::make_unique<Node>("1 ai đó tôi không biết");
    root->no->no->yes->no->no = std::make_unique<Node>("Người là nắng bên đời...?");
    root->no->no->yes->no->no->yes = std::make_unique<Node>("52Hz");
    root->no->no->yes->no->no->no = std::make_unique<Node>("Có liên quan đến Obito?");
    root->no->no->yes->no->no->no->yes = std::make_unique<Node>("VSTRA");
    root->no->no->yes->no->no->no->no = std::make_unique<Node>("Có bài Khi em lớn?");
    root->no->no->yes->no->no->no->no->yes = std::make_unique<Node>("Orange");
    root->no->no->yes->no->no->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");

    root->no->no->no = std::make_unique<Node>("Nghệ danh người này có từ Tiếng Anh?");
    root->no->no->no->yes = std::make_unique<Node>("Có chuyện tình cảm với 1 rapper?");
    root->no->no->no->yes->yes = std::make_unique<Node>("Có chuyện liên quan đến BigDaddy?");
    root->no->no->no->yes->yes->yes = std::make_unique<Node>("Emily");
    root->no->no->no->yes->yes->no = std::make_unique<Node>("Có liên quan đến 16typh?");
    root->no->no->no->yes->yes->no->yes = std::make_unique<Node>("Min");
    root->no->no->no->yes->yes->no->no = std::make_unique<Node>("1 ai đó tôi không biết");
    root->no->no->no->yes->no = std::make_unique<Node>("Có hoạt động bên Trung Quốc?");
    root->no->no->no->yes->no->yes = std::make_unique<Node>("Có bài Anh ơi ở lại?");
    root->no->no->no->yes->no->yes->yes = std::make_unique<Node>("Chi Pu");
    root->no->no->no->yes->no->yes->no = std::make_unique<Node>("Suni Hạ Linh");
    root->no->no->no->yes->no->no = std::make_unique<Node>("Có liên quan đến Anh Tú voi?");
    root->no->no->no->yes->no->no->yes = std::make_unique<Node>("Lyly");
    root->no->no->no->yes->no->no->no = std::make_unique<Node>("Có bài Thị Mầu?");
    root->no->no->no->yes->no->no->no->yes = std::make_unique<Node>("Hòa Minzy");
    root->no->no->no->yes->no->no->no->no = std::make_unique<Node>("Có bài Khi em lớn?");
    root->no->no->no->yes->no->no->no->no->yes = std::make_unique<Node>("Orange");
    root->no->no->no->yes->no->no->no->no->no = std::make_unique<Node>("Từng feat với DaLab?");
    root->no->no->no->yes->no->no->no->no->no->yes = std::make_unique<Node>("Miu Lê");
    root->no->no->no->yes->no->no->no->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");




    root->no->no->no->no = std::make_unique<Node>("Đã lập gia đình?");

    root->no->no->no->no->yes = std::make_unique<Node>("Nghệ danh có 2 từ?");
    root->no->no->no->no->yes->yes = std::make_unique<Node>("Hát dòng Bolero?");
    root->no->no->no->no->yes->yes->yes = std::make_unique<Node>("Lệ Quyên");
    root->no->no->no->no->yes->yes->no = std::make_unique<Node>("Có bài Gửi cho anh?");
    root->no->no->no->no->yes->yes->no->yes = std::make_unique<Node>("Khởi My");
    root->no->no->no->no->yes->yes->no->no = std::make_unique<Node>("Là 1 diva?");
    root->no->no->no->no->yes->yes->no->no->yes = std::make_unique<Node>("Mỹ Linh");
    root->no->no->no->no->yes->yes->no->no->no = std::make_unique<Node>("Có bài Có ai thương em như anh?");
    root->no->no->no->no->yes->yes->no->no->no->yes = std::make_unique<Node>("Tóc Tiên");
    root->no->no->no->no->yes->yes->no->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");
    root->no->no->no->no->yes->no = std::make_unique<Node>("Có bài Cô đơn trên sofa?");
    root->no->no->no->no->yes->no->yes = std::make_unique<Node>("Hồ Ngọc Hà");
    root->no->no->no->no->yes->no->no = std::make_unique<Node>("Có bài Để Mị nói cho mà nghe?");
    root->no->no->no->no->yes->no->no->yes = std::make_unique<Node>("Hoàng Thùy Linh");
    root->no->no->no->no->yes->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");

    root->no->no->no->no->no = std::make_unique<Node>("Nghệ danh có 2 từ?");
    root->no->no->no->no->no->yes = std::make_unique<Node>("Có bài Ước gì?");
    root->no->no->no->no->no->yes->yes = std::make_unique<Node>("Mỹ Tâm");
    root->no->no->no->no->no->yes->no = std::make_unique<Node>("Có chuyện tình cảm với 1 ca sĩ/rapper?");
    root->no->no->no->no->no->yes->no->yes = std::make_unique<Node>("Liên quan đến Hồ Quang Hiếu?");
    root->no->no->no->no->no->yes->no->yes->yes = std::make_unique<Node>("Bảo Anh");
    root->no->no->no->no->no->yes->no->yes->no = std::make_unique<Node>("Liên quan đến Andree?");
    root->no->no->no->no->no->yes->no->yes->no->yes = std::make_unique<Node>("Phương Ly");
    root->no->no->no->no->no->yes->no->yes->no->no = std::make_unique<Node>("1 ai đó tôi không biết");
    root->no->no->no->no->no->yes->no->no = std::make_unique<Node>("Có bài Đi đu đưa đi?");
    root->no->no->no->no->no->yes->no->no->yes = std::make_unique<Node>("Bích Phương");
    root->no->no->no->no->no->yes->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");

    root->no->no->no->no->no->no = std::make_unique<Node>("Nổi tiếng với những bản nhạc nhẹ nhàng?");
    root->no->no->no->no->no->no->yes = std::make_unique<Node>("Có bài Nhiều Người Ôm Giấc Mơ?");
    root->no->no->no->no->no->no->yes->yes = std::make_unique<Node>("Lê Cát Trọng Lý");
    root->no->no->no->no->no->no->yes->no = std::make_unique<Node>("Có bài Ngã Tư Không Đèn?");
    root->no->no->no->no->no->no->yes->no->yes = std::make_unique<Node>("Trang");
    root->no->no->no->no->no->no->yes->no->no = std::make_unique<Node>("1 ai đó tôi không biết");




    root->no->no->no->no->no->no->no = std::make_unique<Node>("Là người miền Bắc?");
    root->no->no->no->no->no->no->no->yes = std::make_unique<Node>("Có bài Mưa Tháng 6?");
    root->no->no->no->no->no->no->no->yes->yes = std::make_unique<Node>("Văn Mai Hương");
    root->no->no->no->no->no->no->no->yes->no = std::make_unique<Node>("Có bài See tình?");
    root->no->no->no->no->no->no->no->yes->no->yes = std::make_unique<Node>("Hoàng Thùy Linh");
    root->no->no->no->no->no->no->no->yes->no->no = std::make_unique<Node>("1 ai đó tôi không biết");
    root->no->no->no->no->no->no->no->no = std::make_unique<Node>("Liên quan đến Sơn Tùng MTP?");
    root->no->no->no->no->no->no->no->no->yes = std::make_unique<Node>("Thiều Bảo Trâm");
    root->no->no->no->no->no->no->no->no->no = std::make_unique<Node>("Có bài Từng là?");
    root->no->no->no->no->no->no->no->no->no->yes = std::make_unique<Node>("Vũ Cát Tường");
    root->no->no->no->no->no->no->no->no->no->no = std::make_unique<Node>("1 ai đó tôi không biết");


    return root;
}

// Khai báo hàm init
bool init(SDL_Window*& window, SDL_Renderer*& renderer, TTF_Font*& font, Mix_Music*& music, Mix_Chunk*& buttonClickSound);

void close(SDL_Window*& window, SDL_Renderer*& renderer, TTF_Font*& font, Mix_Music*& music, Mix_Chunk*& buttonClickSound);
SDL_Texture* loadTexture(SDL_Renderer* renderer, const std::string& path);
SDL_Texture* renderText(SDL_Renderer* renderer, const std::string& text, TTF_Font* font, SDL_Color color);
void gameLoop(SDL_Renderer* renderer, std::map<std::string, SDL_Texture*>& textureMap, TTF_Font* font, Mix_Music*& music, Mix_Chunk*& buttonClickSound);

enum GameState {
    MAIN_MENU,
    PLAY_GAME,
    ADD_QUESTION,
    QUIT_GAME,
    INSTRUCTIONS,
    DATA,
    HOW_TO_PLAY
};

GameState currentState = MAIN_MENU;
bool quit = false;
bool questionEnded = false;
int buttonPressCount = 0; // Biến đếm số lần bấm nút
bool alternateBackground = false;
bool alternate1Background = false; // Cờ để xác định dùng hình nền khác

// Hàm khởi tạo SDL và các thư viện phụ
bool init(SDL_Window*& window, SDL_Renderer*& renderer, TTF_Font*& font, Mix_Music*& music, Mix_Chunk*& buttonClickSound) {



    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cerr << "Không thể khởi tạo SDL! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Game Akinator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Không thể tạo cửa sổ! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Không thể tạo renderer! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) & (IMG_INIT_PNG | IMG_INIT_JPG))) {
        std::cerr << "Không thể khởi tạo SDL_image! IMG_Error: " << IMG_GetError() << std::endl;
        return false;
    }

    if (TTF_Init() == -1) {
        std::cerr << "Không thể khởi tạo SDL_ttf! TTF_Error: " << TTF_GetError() << std::endl;
        return false;
    }

    if (Mix_Init(MIX_INIT_MP3) != MIX_INIT_MP3) {
        std::cerr << "Không thể khởi tạo SDL_mixer! Mix_Error: " << Mix_GetError() << std::endl;
        return false;
    }

    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
        std::cerr << "Không thể mở audio! Mix_Error: " << Mix_GetError() << std::endl;
        return false;
    }
    // Tải âm thanh bấm nút
    buttonClickSound = Mix_LoadWAV("C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\click1.wav");
    if (!buttonClickSound) {
        std::cerr << "Không thể tải âm thanh bấm nút! Mix_Error: " << Mix_GetError() << std::endl;
        return false;
    }
    font = TTF_OpenFont("C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\RobotoSlab-VariableFont_wght.ttf", 24);  // Đảm bảo thay đường dẫn font đúng
    if (!font) {
        std::cerr << "Không thể tải phông chữ! TTF_Error: " << TTF_GetError() << std::endl;
        return false;
    }

    music = Mix_LoadMUS("C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\song.mp3");  // Đảm bảo đường dẫn tới file nhạc nền đúng
    if (!music) {
        std::cerr << "Không thể tải nhạc nền! Mix_Error: " << Mix_GetError() << std::endl;
        return false;
    }

    return true;
}


// Hàm để render văn bản lên màn hình
SDL_Texture* renderText(SDL_Renderer* renderer, const std::string& text, TTF_Font* font, SDL_Color color) {
    SDL_Surface* textSurface = TTF_RenderUTF8_Blended(font, text.c_str(), color);
    if (!textSurface) {
        std::cerr << "Không thể tạo surface từ văn bản! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    return textTexture;
}

void close(SDL_Window*& window, SDL_Renderer*& renderer, TTF_Font*& font, Mix_Music*& music, Mix_Chunk*& buttonClickSound) {
    // Dọn dẹp tài nguyên âm thanh
    Mix_FreeChunk(buttonClickSound);

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    TTF_Quit();
    Mix_Quit();
    SDL_Quit();
}

SDL_Texture* loadTexture(SDL_Renderer* renderer, const std::string& path) {
    SDL_Texture* newTexture = IMG_LoadTexture(renderer, path.c_str());
    if (!newTexture) {
        std::cerr << "Không thể tải hình ảnh: " << IMG_GetError() << std::endl;
    }
    return newTexture;
}

void gameLoop(SDL_Renderer* renderer, std::map<std::string, SDL_Texture*>& textureMap, TTF_Font* font, Mix_Music*& music, Mix_Chunk*& buttonClickSound) {
    SDL_Event e;
    bool quit = false;
    bool showGdchImage = false;
    bool showInstructionImage = false;
    bool showDataImage = false;
    bool isMuted = false;
    auto questionTree = createTree();
    Node* currentNode = questionTree.get();


    // Bắt đầu phát nhạc nền khi game bắt đầu
    if (Mix_PlayingMusic() == 0) {
        Mix_PlayMusic(music, -1);  // Phát nhạc nền, lặp lại vô hạn
    }

    SDL_Texture* background = textureMap["background"];
    SDL_Texture* startButton = textureMap["startButton"];
    SDL_Texture* instructionsButton = textureMap["instructionsButton"];
    SDL_Texture* quitButton = textureMap["quitButton"];
    SDL_Texture* gdchImage = textureMap["gdch"];
    SDL_Texture* dsdataImage = textureMap["dsdata"];
    SDL_Texture* incorrectButton = textureMap["incorrectButton"];
    SDL_Texture* correctButton = textureMap["correctButton"];
    SDL_Texture* instructionImage = textureMap["instructionimage"];
    SDL_Texture* homeButton = textureMap["home"];
    SDL_Texture* dataButton = textureMap["data"];
    SDL_Texture* restartButton = textureMap["restartButton"];

    // Vị trí các nút
    SDL_Rect startButtonRect = { 48, 400, 240, 190 };
    SDL_Rect instructionsButtonRect = { 290, 400, 240, 190 };
    SDL_Rect quitButtonRect = { 530, 400, 236, 186 };
    SDL_Rect correctButtonRect = { 280, 190, 80, 70 };  // Vị trí nút Correct
    SDL_Rect incorrectButtonRect = { 500, 190, 80, 70 };  // Vị trí nút Incorrect
    SDL_Rect dataButtonRect = { 590, 30, 200, 70 };
    SDL_Rect homeButtonRect = { 40, 10, 60, 60 };  // Vị trí nút Home trong instructionimage
    SDL_Rect homeButtonInDataRect = { 40, 10, 50, 50 };  // Vị trí nút Home trong dsdata
    SDL_Rect restartButtonRect = { 500, 190, 200, 70 };


    // Biến mới để kiểm tra câu hỏi kết thúc
    bool questionEnded = false;

    // Khai báo con trỏ
    SDL_Cursor* handCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
    SDL_Cursor* defaultCursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);



    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }

            int x, y;
            SDL_GetMouseState(&x, &y);

            // Kiểm tra nếu chuột di chuyển vào các nút và thay đổi con trỏ
            bool mouseOnButton = false;

            if (currentState == MAIN_MENU) {
                if ((x > startButtonRect.x && x < startButtonRect.x + startButtonRect.w &&
                    y > startButtonRect.y && y < startButtonRect.y + startButtonRect.h) ||
                    (x > instructionsButtonRect.x && x < instructionsButtonRect.x + instructionsButtonRect.w &&
                        y > instructionsButtonRect.y && y < instructionsButtonRect.y + instructionsButtonRect.h) ||
                    (x > quitButtonRect.x && x < quitButtonRect.x + quitButtonRect.w &&
                        y > quitButtonRect.y && y < quitButtonRect.y + quitButtonRect.h)) {
                    mouseOnButton = true;

                }
            }
            if (currentState == HOW_TO_PLAY) {
                if ((x > homeButtonRect.x && x < homeButtonRect.x + homeButtonRect.w &&
                    y > homeButtonRect.y && y < homeButtonRect.y + homeButtonRect.h)) {
                    mouseOnButton = true;

                }

            }
            if (currentState == PLAY_GAME && questionEnded == false) {
                if ((x > correctButtonRect.x && x < correctButtonRect.x + correctButtonRect.w &&
                    y > correctButtonRect.y && y < correctButtonRect.y + correctButtonRect.h)
                    || (x > incorrectButtonRect.x && x < incorrectButtonRect.x + incorrectButtonRect.w &&
                        y > incorrectButtonRect.y && y < incorrectButtonRect.y + incorrectButtonRect.h) || (x > homeButtonRect.x && x < homeButtonRect.x + homeButtonRect.w &&
                            y > homeButtonRect.y && y < homeButtonRect.y + homeButtonRect.h)
                    ) {
                    mouseOnButton = true;

                }

            }
            if (currentState == PLAY_GAME && questionEnded) {
                if ((x > restartButtonRect.x && x < restartButtonRect.x + restartButtonRect.w &&
                    y > restartButtonRect.y && y < restartButtonRect.y + restartButtonRect.h) ||
                    (x > homeButtonRect.x && x < homeButtonRect.x + homeButtonRect.w &&
                        y > homeButtonRect.y && y < homeButtonRect.y + homeButtonRect.h)

                    ) {
                    mouseOnButton = true;

                }

            }


            // Nếu chuột ở trên nút, đổi con trỏ thành bàn tay
            if (mouseOnButton) {
                SDL_SetCursor(handCursor);
            }
            else {
                SDL_SetCursor(defaultCursor);
            }
            if (currentState == MAIN_MENU && e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);

                if (x > startButtonRect.x && x < startButtonRect.x + startButtonRect.w &&
                    y > startButtonRect.y && y < startButtonRect.y + startButtonRect.h) {
                    currentState = PLAY_GAME;  // Chuyển sang chơi game
                    showGdchImage = true;  // Hiển thị ảnh gdch
                    Mix_PlayChannel(-1, buttonClickSound, 0);
                }

                if (x > instructionsButtonRect.x && x < instructionsButtonRect.x + instructionsButtonRect.w &&
                    y > instructionsButtonRect.y && y < instructionsButtonRect.y + instructionsButtonRect.h) {
                    currentState = HOW_TO_PLAY; // Chuyển sang màn hình hướng dẫn
                    showInstructionImage = true;  // Hiển thị ảnh hướng dẫn
                    Mix_PlayChannel(-1, buttonClickSound, 0);
                }

                if (x > quitButtonRect.x && x < quitButtonRect.x + quitButtonRect.w &&
                    y > quitButtonRect.y && y < quitButtonRect.y + quitButtonRect.h) {
                    quit = true;
                    Mix_PlayChannel(-1, buttonClickSound, 0);
                }
            }

            // Trong trạng thái PLAY_GAME, hiển thị nút Correct và Incorrect
            if (currentState == PLAY_GAME && e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x > homeButtonRect.x && x < homeButtonRect.x + homeButtonRect.w &&
                    y > homeButtonRect.y && y < homeButtonRect.y + homeButtonRect.h) {
                    currentNode = questionTree.get();
                    currentState = MAIN_MENU;  // Quay lại menu chính
                    Mix_PlayChannel(-1, buttonClickSound, 0);
                }


                // Khi câu hỏi kết thúc, chỉ hiển thị nút "Chơi lại" hoặc "Home"
                if (questionEnded) {
                    // Nếu click vào nút Home
                    if (x > homeButtonRect.x && x < homeButtonRect.x + homeButtonRect.w &&
                        y > homeButtonRect.y && y < homeButtonRect.y + homeButtonRect.h) {
                        currentNode = questionTree.get();
                        currentState = MAIN_MENU;  // Quay lại menu chính
                        Mix_PlayChannel(-1, buttonClickSound, 0);
                    }
                    // Nếu click vào nút "Chơi lại"
                    if (x > restartButtonRect.x && x < restartButtonRect.x + restartButtonRect.w &&
                        y > restartButtonRect.y && y < restartButtonRect.y + restartButtonRect.h) {
                        currentNode = questionTree.get(); // Reset lại câu hỏi
                        questionEnded = false;
                        alternateBackground = false;
                        alternate1Background = false;
                        buttonPressCount = 0; // chạy lại biến đếm số lần Đúng sai
                        currentState = PLAY_GAME; // Tiếp tục chơi game
                        Mix_PlayChannel(-1, buttonClickSound, 0);
                    }
                }

                // Khi câu hỏi chưa kết thúc, người chơi có thể chọn "Đúng" hoặc "Sai"
                else {
                    if (x > correctButtonRect.x && x < correctButtonRect.x + correctButtonRect.w &&
                        y > correctButtonRect.y && y < correctButtonRect.y + correctButtonRect.h) {
                        if (currentNode->yes) {
                            buttonPressCount++;
                            currentNode = currentNode->yes.get();
                            Mix_PlayChannel(-1, buttonClickSound, 0);
                        }
                        else {
                            questionEnded = true;  // Câu hỏi kết thúc, hiển thị nút "Chơi lại" và "Home"
                        }
                    }


                    if (x > incorrectButtonRect.x && x < incorrectButtonRect.x + incorrectButtonRect.w &&
                        y > incorrectButtonRect.y && y < incorrectButtonRect.y + incorrectButtonRect.h) {
                        buttonPressCount++; // Tăng đếm khi bấm "Sai"
                        if (currentNode->no) {
                            currentNode = currentNode->no.get();
                            Mix_PlayChannel(-1, buttonClickSound, 0);
                        }
                        else {
                            questionEnded = true;  // Câu hỏi kết thúc, hiển thị nút "Chơi lại" và "Home"
                        }
                    }
                }
            }

            // Kiểm tra nếu đã bấm đủ số lần
            if (buttonPressCount == 4) {
                alternateBackground = true; // Kích hoạt hình nền thay thế
            }
            else if (buttonPressCount == 7) {
                alternate1Background = true;
            }
            else {
                showGdchImage = true;
            }

            // Trong trạng thái HOW_TO_PLAY
            if (currentState == HOW_TO_PLAY && e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);


                // Kiểm tra nếu người dùng bấm vào nút "Home"
                if (x > homeButtonRect.x && x <  homeButtonRect.x + homeButtonRect.w &&
                    y >  homeButtonRect.y && y < homeButtonRect.y + homeButtonRect.h) {
                    currentState = MAIN_MENU; // Trở lại màn hình chính
                    Mix_PlayChannel(-1, buttonClickSound, 0);
                }

            }

            // Trạng thái DATA
            if (currentState == DATA && e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);

                // Kiểm tra nếu bấm vào nút Home trong màn hình dsdata
                if (x > homeButtonRect.x && x < homeButtonRect.x + homeButtonRect.w &&
                    y > homeButtonRect.y && y < homeButtonRect.y + homeButtonRect.h) {
                    currentState = MAIN_MENU;  // Quay lại menu chính
                    showDataImage = false;
                    Mix_PlayChannel(-1, buttonClickSound, 0);
                }
            }
        }

        // Render màn hình
        SDL_RenderClear(renderer);

        // Vẽ nền
        SDL_RenderCopy(renderer, background, nullptr, nullptr);

        // Hiển thị các nút trong trạng thái MAIN_MENU
        if (currentState == MAIN_MENU) {
            SDL_RenderCopy(renderer, startButton, nullptr, &startButtonRect);
            SDL_RenderCopy(renderer, instructionsButton, nullptr, &instructionsButtonRect);
            SDL_RenderCopy(renderer, quitButton, nullptr, &quitButtonRect);
        }

        // Hiển thị ảnh hướng dẫn
        if (showInstructionImage && currentState == HOW_TO_PLAY) {
            SDL_RenderCopy(renderer, instructionImage, nullptr, nullptr);

            SDL_RenderCopy(renderer, homeButton, nullptr, &homeButtonRect);

        }

        // Hiển thị ảnh dsdata
        if (showDataImage && currentState == DATA) {
            SDL_RenderCopy(renderer, dsdataImage, nullptr, nullptr);
        }

        // Hiển thị ảnh gdch
        if (showGdchImage && currentState == PLAY_GAME) {
            // Chọn hình nền dựa trên cờ alternateBackground
            if (alternateBackground) {
                SDL_Texture* alternateBg = textureMap["alternateBackground"];
                SDL_RenderCopy(renderer, alternateBg, nullptr, nullptr);
                if (alternate1Background) {
                    SDL_Texture* alternate1Bg = textureMap["alternate1Background"];
                    SDL_RenderCopy(renderer, alternate1Bg, nullptr, nullptr);

                }
            }
            else {
                SDL_RenderCopy(renderer, gdchImage, nullptr, nullptr);
            }
            SDL_RenderCopy(renderer, homeButton, nullptr, &homeButtonRect);

            // Nếu câu hỏi chưa kết thúc, hiển thị nút "Đúng" và "Sai"
            if (!questionEnded) {
                SDL_RenderCopy(renderer, correctButton, nullptr, &correctButtonRect);
                SDL_RenderCopy(renderer, incorrectButton, nullptr, &incorrectButtonRect);

            }
            // Tìm ảnh của nhân vật dựa vào câu trả lời
            SDL_Texture* celebrityImage = textureMap[currentNode->question];
            if (celebrityImage) {
                SDL_Rect celebrityRect = { 300, 260, 340, 320 };  // Vị trí và kích thước hiển thị ảnh
                SDL_RenderCopy(renderer, celebrityImage, nullptr, &celebrityRect);
            }


            // Nếu câu hỏi kết thúc, hiển thị nút "Chơi lại" và "Home"
            if (questionEnded) {

                // Tìm ảnh của nhân vật dựa vào câu trả lời
                SDL_Texture* celebrityImage = textureMap[currentNode->question];
                if (celebrityImage) {
                    SDL_Rect celebrityRect = { 300, 260, 340, 320 };  // Vị trí và kích thước hiển thị ảnh
                    SDL_RenderCopy(renderer, celebrityImage, nullptr, &celebrityRect);
                }
                SDL_RenderCopy(renderer, restartButton, nullptr, &restartButtonRect);
                SDL_RenderCopy(renderer, homeButton, nullptr, &homeButtonRect);
            }

            // Hiển thị câu hỏi
            if (!currentNode->question.empty()) {
                SDL_Surface* surfaceMessage = TTF_RenderUTF8_Blended(font, currentNode->question.c_str(), { 0, 0, 0 });
                SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

                SDL_Rect messageRect = { 260, 110, surfaceMessage->w, surfaceMessage->h };
                SDL_RenderCopy(renderer, message, nullptr, &messageRect);

                SDL_FreeSurface(surfaceMessage);
                SDL_DestroyTexture(message);
            }
        }

        // Hiển thị lại mọi thứ
        SDL_RenderPresent(renderer);
    }
}


int main(int argc, char* args[]) {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    TTF_Font* font = nullptr;
    Mix_Music* music = nullptr;
    Mix_Chunk* buttonClickSound = nullptr;


    if (!init(window, renderer, font, music, buttonClickSound)) {
        std::cerr << "Khởi tạo thất bại!" << std::endl;
        close(window, renderer, font, music, buttonClickSound);
        return -1;
    }

    std::map<std::string, SDL_Texture*> textureMap;
    textureMap["background"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\theme.png");
    textureMap["startButton"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\bdau.png");
    textureMap["instructionsButton"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\cachchoi.png");
    textureMap["quitButton"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\thoát.png");
    textureMap["gdch"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\gd2.png");
    textureMap["dsdata"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\dsdata.png");
    textureMap["incorrectButton"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\false.png");
    textureMap["playgame"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\gd1.png");
    textureMap["home"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\home.png");
    textureMap["data"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\data.png");
    textureMap["instructionimage"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\hdcc.jpg");
    textureMap["correctButton"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\true.png");
    textureMap["restartButton"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\restart.png");
    textureMap["alternateBackground"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\gd1.png");
    textureMap["alternate1Background"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\gd3.png");

    //Danh sách ảnh nghệ sĩ
    textureMap["1 ai đó tôi không biết"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\người không trong dữ liệu.png");
    textureMap["Hieuthuhai"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Hieuthuhai.jpg");
    textureMap["16typh"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\16typh.webp");
    textureMap["24kRight"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\24kRight.jpg");
    textureMap["52Hz"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\52Hz.jpeg");
    textureMap["Amee"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Amee.jpg");
    textureMap["Andree Right Hand"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Andree Right Hand.jpg");
    textureMap["Anh Tú"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Anh Tú.webp");
    textureMap["Bằng Kiều"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Bằng Kiều.jpg");
    textureMap["Bảo Anh"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Bảo Anh.jpg");
    textureMap["Bích Phương"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Bích Phương.png");
    textureMap["BigDaddy"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\BigDaddy.jpg");
    textureMap["Bình Gold"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Bình Gold.webp");
    textureMap["Binz"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Binz.jpg");
    textureMap["Blacka"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Blacka.webp");
    textureMap["Bray"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Bray.png");
    textureMap["Vũ Thanh Vân"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Vũ Thanh Vân.png");
    textureMap["Vũ"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Vũ.webp");
    textureMap["Wowy"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Wowy.jpeg");
    textureMap["Wren Evans"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Wren Evans.webp");
    textureMap["Wxrdie"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Wxrdie.jpg");
    textureMap["Yuno Bigboy"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Yuno Bigboy.webp");
    textureMap["Bùi Công Nam"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Bùi Công Nam.jpg");
    textureMap["Captain"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Captain.webp");
    textureMap["Chi Dân"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Chi Dân.jpeg");
    textureMap["Chi Pu"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Chi Pu.jpg");
    textureMap["Coldzy"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Coldzy.jpg");
    textureMap["Dangrangto"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Dangrangto.jpg");
    textureMap["Datmaniac"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Datmaniac.jpg");
    textureMap["Dế Choắt"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Dế Choắt.jpg");
    textureMap["Đen Vâu"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Đen Vâu.jpg");
    textureMap["Dlow"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Dlow.webp");
    textureMap["Đỗ Phú Quí"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Đỗ Phú Quí.jpg");
    textureMap["Double2T"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Double2T.webp");
    textureMap["DSK"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\DSK.webp");
    textureMap["Đức Phúc"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Đức Phúc.jpg");
    textureMap["Dương Domic"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Dương Domic.webp");
    textureMap["Emily"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Emily.jpg");
    textureMap["Erik"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Erik.jpg");
    textureMap["Gducky"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Gducky.jpg");
    textureMap["Hà Anh Tuấn"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Hà Anh Tuấn.webp");
    textureMap["HuyR"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\HuyR.jpg");
    textureMap["Hazel"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Hazel.webp");
    textureMap["Hồ Ngọc Hà"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Hồ Ngọc Hà.jpg");
    textureMap["Hồ Quang Hiếu"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Hồ Quang Hiếu.png");
    textureMap["Hòa Minzy"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Hòa Minzy.webp");
    textureMap["Hoàng Dũng"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Hoàng Dũng.webp");
    textureMap["Hoàng Thùy Linh"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Hoàng Thùy Linh.jpg");
    textureMap["Hứa Kim Tuyền"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Hứa Kim Tuyền.webp");
    textureMap["Hưng Cao"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Hưng Cao.jpg");
    textureMap["HurryKng"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\HurryKng.webp");
    textureMap["Huỳnh Công Hiếu"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Huỳnh Công Hiếu.jpg");
    textureMap["Isaac"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Isaac.jpeg");
    textureMap["Jack 5 củ"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Jack 5 củ.jpg");
    textureMap["Jun Phạm"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Jun Phạm.jpeg");
    textureMap["JustaTee"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\JustaTee.jpg");
    textureMap["Karik"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Karik.jpg");
    textureMap["Kay Trần"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Kay Trần.jpg");
    textureMap["Khắc Việt"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Khắc Việt.jpg");
    textureMap["Khởi My"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Khởi My.webp");
    textureMap["Khói"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Khói.jpg");
    textureMap["Kiên aka Trịnh Trung Kiên"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Kiên.jpg");
    textureMap["Lăng LD"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Lăng LD.webp");
    textureMap["Lê Cát Trọng Lý"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Lê Cát Trọng Lý.jpg");
    textureMap["Lệ Quyên"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Lệ Quyên.webp");
    textureMap["Lil Wuyn"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Lil Wuyn.webp");
    textureMap["Liu Grace"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Liu Grace.png");
    textureMap["LowG"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\LowG.webp");
    textureMap["Lou Hoàng"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Lou Hoàng.jpg");
    textureMap["Lyly"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Lyly.jpg");
    textureMap["MCK"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\MCK.webp");
    textureMap["Mikelodic"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Mikelodic.webp");
    textureMap["Min"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Min.jpg");
    textureMap["Miu Lê"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Miu Lê.webp");
    textureMap["Mr Siro"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Mr Siro.jpg");
    textureMap["Mỹ Linh"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Mỹ Linh.webp");
    textureMap["Mỹ Tâm"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Mỹ Tâm.jpg");
    textureMap["Negav"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Negav.jpg");
    textureMap["Noo Phước Thịnh"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Noo Phước Thịnh.webp");
    textureMap["Obito"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Obito.webp");
    textureMap["Orange"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Orange.jpg");
    textureMap["Phan Đinh Tùng"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Phan Đinh Tùng.webp");
    textureMap["Phan Mạnh Quỳnh"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Phan Mạnh Quỳnh.jpeg");
    textureMap["Pháo"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Pháo.jpg");
    textureMap["Pháp Kiều"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Pháp Kiều.jpg");
    textureMap["Phúc Du"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Phúc Du.jpg");
    textureMap["Phương Ly"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Phương Ly.jpg");
    textureMap["Phương Mỹ Chi"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Phương Mỹ Chi.webp");
    textureMap["Quân AP"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Quân AP.webp");
    textureMap["Quang Hùng MasterD"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Quang Hùng MasterD.jpg");
    textureMap["Rhyder"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Rhyder.jpg");
    textureMap["Rhymastic"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Rhymastic.jpg");
    textureMap["Richchoi"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Richchoi.jpg");
    textureMap["Ricky Star"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Ricky Star.jpg");
    textureMap["Robber"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Robber.jpg");
    textureMap["Seachains"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Seachains.jpg");
    textureMap["Sofia"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Sofia.webp");
    textureMap["Sơn Tùng MTP"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Sơn Tùng MTP.webp");
    textureMap["Soobin Hoàng Sơn"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Soobin Hoàng Sơn.webp");
    textureMap["ST Sơn Thạch"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\ST Sơn Thạch.jpg");
    textureMap["Suboi"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Suboi.webp");
    textureMap["Suni Hạ Linh"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Suni Hạ Linh.jpg");
    textureMap["Tăng Duy Tân"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Tăng Duy Tân.webp");
    textureMap["Táo"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Táo.webp");
    textureMap["Tez"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Tez.jpg");
    textureMap["Thắng aka Vũ Đình Trọng Thắng"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Thắng.jpg");
    textureMap["Thành Draw"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Thành Draw.webp");
    textureMap["Trang"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Trang.jpg");
    textureMap["Thiều Bảo Trâm"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Thiều Bảo Trâm.jpg");
    textureMap["Thịnh Suy"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Thịnh Suy.jpg");
    textureMap["Tlinh"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Tlinh.jpg");
    textureMap["Tóc Tiên"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Tóc Tiên.jpg");
    textureMap["Trúc Nhân"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Trúc Nhân.jpg");
    textureMap["Tuấn Hưng"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Tuấn Hưng.webp");
    textureMap["Tùng Dương"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Tùng Dương.jpg");
    textureMap["Văn Mai Hương"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Văn Mai Hương.png");
    textureMap["VSoul"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\VSoul.webp");
    textureMap["VSTRA"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\VSTRA.jpg");
    textureMap["Vũ Cát Tường"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Vũ Cát Tường.jpg");
    textureMap["Anh Phan"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Anh Phan.jpg");
    textureMap["Khánh Phương"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Khánh Phương.webp");
    textureMap["Đàm Vĩnh Hưng"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Đàm Vĩnh Hưng.jpg");
    textureMap["Cậu Phát"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Cậu Phát.jpg");
    textureMap["CCMK"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\CCMK.jpg");
    textureMap["Left Hand"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Left Hand.jpg");
    textureMap["Lil Van"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Lil Van.jpg");
    textureMap["Gill"] = loadTexture(renderer, "C:\\Users\\admin\\source\\repos\\GameAkinator\\GameAkinator\\x64\\Debug\\Gill.webp");



    gameLoop(renderer, textureMap, font, music, buttonClickSound);

    close(window, renderer, font, music, buttonClickSound);
    return 0;
}


