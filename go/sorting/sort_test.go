package sorting

import (
	"sort"
	"math/rand"
	"time"
	"testing"
)

func init() {
	rand.Seed(time.Now().Unix())
}

func generateRandomInts(max, length int) *sort.IntSlice {
	data := make([]int, length)
	for i := 0; i < length; i++ {
		data[i] = rand.Int()%max
	}
	is := sort.IntSlice(data)
	return &is
}

func TestQuickSort(t *testing.T) {
	data := generateRandomInts(100, 99)
	t.Logf("%+v\n", data)
	QuickSort(data)
	t.Logf("%+v\n", data)
}

func TestBubbleSort(t *testing.T) {
	data := generateRandomInts(100, 99)
	t.Logf("%+v\n", data)
	BubbleSort(data)
	t.Logf("%+v\n", data)
}
