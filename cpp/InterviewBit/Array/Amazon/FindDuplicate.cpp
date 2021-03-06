#include<bits/stdc++.h>
using namespace std;

void print_bucket(int b[], int i, int l, int h){
    cout << " bucket " << i << "," << b[i] << " :";
    for(int i=l; i<=h; i++){
        cout << i << " ";
    }
    cout << endl;
}

int repeatedNumber(int A[], int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int ans = -1;
    int bucket_size = (int)(sqrt(n) + 1) ;
    cout << "bucket size :" << bucket_size << ", ";


    //if(bucket_size * bucket_size < n-1)
        //bucket_size++;
    cout << "number of buckets :" << bucket_size+1 << endl;


    int b[bucket_size+1];
    memset(b, 0, sizeof(b));

    //[1 sqrt(n))  [sqrt(n) 2*sqrt(n))  [2*sqrt(n) 3*sqrt(n))
    //size of each bucket is sqrt(n)-1    for ex. sqrt(16)=4  -> [1,4) [4,7) [8,12) [12,16)

    //increment count of bucket if number lies in its range
    for(int i=0; i< n; i++){
        b[(int)((A[i]-1)/bucket_size)]++;
        //cout << "adding " << A[i] << " to bucket " << (int)((A[i]-1)/bucket_size) << endl;
    }


    for(int i=0; i<bucket_size+1; i++){
        print_bucket(b, i, i*bucket_size + 1, (i+1) * bucket_size);
    }

    int repeating_bucket = -1;

    for(int i=0; i<=bucket_size+1; i++){
        //if b[i] = number of elements in bucket b[i] is greater than bucket_size
        //then there is repetition of numbers in ith bucket
        if(b[i] > bucket_size){
            repeating_bucket = i;
            break;
        }
    }


    //range of this bucket -> [repeating_buckrt*sqrt(n)  (repeating_bucket+1) *sqrt(n))
    map<int,int> m;
    int l = (repeating_bucket*bucket_size)+1;
    int h = (repeating_bucket+1)*bucket_size;

    cout << "repeating " << repeating_bucket << " [" << l << " " << h << "]";

    for(int i=0; i<n; i++){
        if(A[i] >= l && A[i] <= h){
            if(m[A[i]] == 0)
                m[A[i]]++;
            else{
               ans = A[i];
               break;
            }
        }
    }

    return ans;
}



int main(){

    int A[] = {442, 249, 406, 112, 202, 98, 228, 99, 38, 10, 402, 505, 104, 340, 265, 317, 190, 403, 148, 276, 145, 199, 456, 489, 237, 226, 470, 342, 405, 339, 142, 234, 542, 96, 71, 297, 261, 262, 130, 119, 428, 82, 432, 219, 430, 439, 188, 397, 227, 478, 400, 111, 451, 388, 34, 303, 158, 68, 74, 502, 36, 80, 243, 508, 73, 324, 103, 325, 46, 211, 133, 144, 480, 404, 231, 416, 401, 370, 3, 48, 407, 195, 212, 300, 47, 409, 44, 21, 248, 105, 56, 319, 117, 149, 334, 455, 544, 429, 464, 143, 75, 197, 316, 292, 352, 282, 525, 194, 87, 242, 283, 333, 356, 440, 338, 100, 366, 368, 520, 129, 479, 499, 408, 496, 307, 173, 347, 101, 293, 523, 114, 5, 393, 178, 329, 394, 302, 59, 492, 175, 537, 538, 454, 217, 84, 344, 126, 360, 471, 433, 238, 465, 62, 165, 43, 139, 530, 512, 280, 312, 518, 385, 8, 29, 93, 467, 320, 64, 120, 452, 391, 358, 522, 445, 274, 240, 172, 449, 205, 18, 328, 453, 278, 536, 69, 331, 166, 92, 50, 462, 501, 27, 106, 72, 30, 11, 289, 318, 343, 245, 497, 411, 218, 363, 151, 85, 37, 337, 285, 511, 137, 426, 155, 254, 376, 136, 235, 90, 418, 60, 487, 181, 232, 486, 287, 515, 362, 86, 395, 255, 159, 527, 336, 378, 375, 115, 15, 179, 33, 67, 177, 247, 51, 424, 284, 357, 157, 162, 253, 135, 216, 122, 41, 118, 359, 209, 355, 373, 437, 23, 214, 97, 191, 447, 83, 267, 256, 20, 52, 236, 39, 259, 204, 353, 510, 55, 203, 305, 290, 206, 413, 488, 14, 380, 174, 540, 299, 463, 485, 371, 309, 186, 481, 192, 200, 156, 288, 534, 475, 382, 184, 152, 220, 189, 521, 443, 110, 160, 369, 171, 183, 468, 65, 108, 427, 423, 516, 146, 384, 138, 222, 35, 365, 163, 458, 132, 498, 372, 66, 345, 326, 396, 40, 141, 22, 491, 19, 286, 415, 434, 121, 1, 270, 313, 78, 446, 379, 392, 31, 9, 180, 420, 45, 76, 26, 460, 49, 89, 279, 54, 57, 208, 519, 241, 275, 386, 441, 533, 296, 507, 422, 109, 196, 361, 2, 4, 474, 182, 53, 310, 414, 291, 364, 61, 535, 398, 134, 24, 509, 335, 484, 263, 476, 154, 304, 25, 306, 444, 32, 266, 210, 539, 473, 322, 7, 466, 529, 436, 350, 494, 16, 161, 116, 459, 168, 301, 215, 213, 91, 438, 102, 224, 277, 13, 17, 28, 258, 70, 531, 541, 532, 315, 187, 381, 170, 272, 147, 223, 252, 421, 81, 271, 201, 164, 176, 58, 257, 321, 95, 377, 472, 113, 94, 457, 153, 469, 225, 140, 399, 281, 308, 230, 193, 390, 514, 483, 412, 327, 12, 543, 367, 493, 504, 419, 524, 198, 77, 295, 417, 389, 374, 435, 42, 330, 528, 311, 490, 387, 341, 517, 127, 298, 169, 185, 125, 233, 410, 477, 128, 239, 107, 448, 354, 221, 425, 264, 294, 323, 88, 526, 124, 351, 349, 506, 150, 348, 246, 482, 260, 251, 167, 503, 250, 268, 273, 207, 540, 332, 63, 431, 131, 383, 6, 495, 244, 346, 269, 79, 450, 513, 123, 461, 314, 229, 500};
    cout << repeatedNumber(A, sizeof(A)/sizeof(A[0]));
    return 0;
}
