// NOT DONE

int max, min;
        sort(arr, arr + n);
        if(arr[n-1] - arr[0] < k || arr[n-1] <= k) {
            arr[0] += k;
            arr[n-1] += k;
        } else {
            arr[0] += k;
            arr[n-1] -= k;
        }
        max = arr[0] >= arr[n-1] ? arr[0] : arr[n-1];
        min = arr[0] >= arr[n-1] ? arr[n-1] : arr[0];
        for(int i=1; i<n-1; i++) {
            if(arr[i]<=k) {
                arr[i] += k;
                if(arr[i]<min) min = arr[i];
                if(arr[i]>max) max = arr[i];
            }
            else {
                if (arr[i] + k <= max && arr[i] + k >= min) continue;
                else if (arr[i] - k <= max && arr[i] - k >= min) continue;
                else if (arr[i] + k > max) maxgap = arr[i] + k - max;
                else if (arr[i] - k > max) maxgap = arr[i] - k - max;
                
                else if (arr[i] + k < min) mingap = min - arr[i] - k;
                else if (arr[i] - k < min) mingap = min - arr[i] + k;
                if ( min ga)
            }
        }
        return max - min;
