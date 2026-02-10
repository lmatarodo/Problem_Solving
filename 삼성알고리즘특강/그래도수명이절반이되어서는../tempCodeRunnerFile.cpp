
    for (int i = 0; i < n; i++) {
        if (w[i] <= limit){
            cont_count++;

            if (cont_count == s[curr_idx]) { // 현재 배치해야할 덩어리 크기인지 확인
                curr_idx++;
                cont_count = 0;

                if (curr_idx == k) return true; // 만약 모두 배치했다면 성공
            }
        }
        else cont_count = 0; // 연속성이 깨지는 경우
    }