using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while (storey > 0)
    {
        int k = storey % 10;
        storey /= 10;
        
        if (k > 5)
        {
            answer += (10 - k);
            storey++;
        }
        else if (k < 5)
        {
            answer += k;
        }
        else
        {
            int n = storey % 10;
            answer += 5;
            
            if (n >= 5)
            {
                storey++;
            }
        }
    }
    
    return answer;
}