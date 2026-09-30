#include <stdio.h>
#include <string.h>

int main() {
    char maPhieu[100][20];
    char maSach[100][20];
    int soNgayMuon[100];
    int soLuong = 0;
    int choice;

    do {
        printf("\n================ HE THONG QUAN LY MUON TRA SACH (LOGISTICS) ================\n");
        printf("1. Them moi phieu muon sach (Create)\n");
        printf("2. Hien thi danh sach phieu muon & Tien phat qua han (Read)\n");
        printf("3. Cap nhat so ngay muon sach (Update)\n");
        printf("4. Xac nhan tra sach / Xoa phieu muon (Delete)\n");
        printf("5. Thoat chuong trinh\n");
        printf("===========================================================================\n");
        printf("Lua chon cua ban (1-5): ");
        scanf("%d", &choice);
        while(getchar() != '\n');

        switch(choice) {
            case 1:
                if (soLuong >= 100) {
                    printf("Bo nho danh sach da day, khong the them moi!\n");
                } else {
                    printf("--- THEM MOI PHIEU MUON ---\n");
                    char newMaPhieu[20];
                    printf("Nhap ma phieu: ");
                    scanf("%19s", newMaPhieu);
                    while(getchar() != '\n');

                    int exists = 0;
                    for (int i = 0; i < soLuong; i++) {
                        if (strcmp(maPhieu[i], newMaPhieu) == 0) {
                            exists = 1;
                            break;
                        }
                    }

                    if (exists) {
                        printf("Ma phieu da ton tai trong he thong!\n");
                    } else {
                        strcpy(maPhieu[soLuong], newMaPhieu);
                        printf("Nhap ma sach: ");
                        scanf("%19s", maSach[soLuong]);
                        while(getchar() != '\n');

                        int ngay;
                        do {
                            printf("Nhap so ngay muon: ");
                            scanf("%d", &ngay);
                            while(getchar() != '\n');
                            if (ngay <= 0) printf("So ngay muon phai > 0!\n");
                        } while (ngay <= 0);

                        soNgayMuon[soLuong] = ngay;
                        soLuong++;
                        printf("Them moi phieu muon thanh cong!\n");
                    }
                }
                break;

            case 2:
                if (soLuong == 0) {
                    printf("Danh sach phieu muon hien dang rong!\n");
                } else {
                    printf("\n================================ DANH SACH PHIEU MUON ================================\n");
                    printf("%-5s %-15s %-15s %-10s %-15s %-15s\n", "STT", "MA PHIEU", "MA SACH", "SO NGAY", "TRANG THAI", "TIEN PHAT (VND)");
                    for (int i = 0; i < soLuong; i++) {
                        int tienPhat = 0;
                        const char* trangThai = "DUNG HAN";
                        if (soNgayMuon[i] > 14) {
                            tienPhat = (soNgayMuon[i] - 14) * 5000;
                            trangThai = "QUA HAN";
                        }
                        printf("%-5d %-15s %-15s %-10d %-15s %-15d\n", i + 1, maPhieu[i], maSach[i], soNgayMuon[i], trangThai, tienPhat);
                    }
                    printf("======================================================================================\n");
                }
                break;

            case 3:
                {
                    char target[20];
                    printf("Nhap ma phieu can cap nhat: ");
                    scanf("%19s", target);
                    while(getchar() != '\n');

                    int idx = -1;
                    for (int i = 0; i < soLuong; i++) {
                        if (strcmp(maPhieu[i], target) == 0) {
                            idx = i;
                            break;
                        }
                    }

                    if (idx == -1) {
                        printf("Khong tim thay ma phieu trong he thong!\n");
                    } else {
                        printf("So ngay muon hien tai cua phieu %s la: %d\n", maPhieu[idx], soNgayMuon[idx]);
                        int ngayMoi;
                        do {
                            printf("Nhap so ngay muon moi: ");
                            scanf("%d", &ngayMoi);
                            while(getchar() != '\n');
                            if (ngayMoi <= 0) printf("So ngay muon phai > 0!\n");
                        } while (ngayMoi <= 0);
                        soNgayMuon[idx] = ngayMoi;
                        printf("Cap nhat so ngay muon thanh cong!\n");
                    }
                }
                break;

            case 4:
                {
                    char target[20];
                    printf("Nhap ma phieu xac nhan tra/xoa: ");
                    scanf("%19s", target);
                    while(getchar() != '\n');

                    int idx = -1;
                    for (int i = 0; i < soLuong; i++) {
                        if (strcmp(maPhieu[i], target) == 0) {
                            idx = i;
                            break;
                        }
                    }

                    if (idx == -1) {
                        printf("Khong tim thay ma phieu can xoa!\n");
                    } else {
                        for (int i = idx; i < soLuong - 1; i++) {
                            strcpy(maPhieu[i], maPhieu[i + 1]);
                            strcpy(maSach[i], maSach[i + 1]);
                            soNgayMuon[i] = soNgayMuon[i + 1];
                        }
                        soLuong--;
                        printf("Xac nhan tra sach va xoa phieu muon thanh cong!\n");
                    }
                }
                break;

            case 5:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
