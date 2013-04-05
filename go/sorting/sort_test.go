package sorting

import (
	"math/rand"
	"sort"
	"testing"
	"time"
)

func init() {
	rand.Seed(time.Now().Unix())
}

func generateRandomInts(max, length int) []int {
	data := make([]int, length)
	for i := 0; i < length; i++ {
		data[i] = rand.Int() % max
	}
	return data
}

func TestQuickSort(t *testing.T) {
	data := generateRandomInts(1000, 100)
	t.Logf("%+v\n", data)
	QuickSort(sort.IntSlice(data))
	t.Logf("%+v\n", data)
}

func TestBubbleSort(t *testing.T) {
	data := generateRandomInts(1000, 100)
	t.Logf("%+v\n", data)
	BubbleSort(sort.IntSlice(data))
	t.Logf("%+v\n", data)
}

func TestMixed(t *testing.T) {
	dataQ := generateRandomInts(1000, 100)
	dataB := make([]int, 100)
	for i := 0; i < 100; i++ {
		dataB[i] = dataQ[i]
	}
	QuickSort(sort.IntSlice(dataQ))
	BubbleSort(sort.IntSlice(dataB))
	for i := 0; i < 100; i++ {
		if dataB[i] != dataQ[i] {
			t.Fatalf("dataB[i]:%d != dataQ[i]:%d\n", dataB[i], dataQ[i])
		}
	}

}
