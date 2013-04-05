package sorting

import (
	"sort"
)

func quickSort(data sort.Interface, low, high int) {
	if low >= high {
		return
	}

	l := low
	h := high
	for l < h {
		if data.Less(l+1, l) {
			data.Swap(l, l+1)
			l++
		} else {
			data.Swap(l+1, h)
			h--
		}
	}

	if low < l-1 {
		quickSort(data, low, l-1)
	}

	if high > l+1 {
		quickSort(data, l+1, high)
	}
}

func QuickSort(data sort.Interface) {
	quickSort(data, 0, data.Len()-1)
}

func BubbleSort(data sort.Interface) {
	length := data.Len()
	for i := 0; i < length-1; i++ {
		for j := i + 1; j < length; j++ {
			if data.Less(j, i) {
				data.Swap(j, i)
			}
		}
	}
}
