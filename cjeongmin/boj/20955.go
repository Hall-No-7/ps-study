package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type DisjointSet struct {
	parent []int
}

var (
	in  = bufio.NewScanner(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func println(arg ...interface{}) { fmt.Fprintln(out, arg...) }

func nextInt() int {
	in.Scan()
	n, _ := strconv.Atoi(in.Text())
	return n
}

func NewDisjointSet(size int) *DisjointSet {
	res := new(DisjointSet)
	res.parent = make([]int, size)
	for i := 1; i < size; i++ {
		res.parent[i] = i
	}
	return res
}

func (self *DisjointSet) find(x int) int {
	if self.parent[x] == x {
		return x
	}
	alt := self.find(self.parent[x])
	self.parent[x] = alt
	return alt
}

func (self *DisjointSet) union(x, y int) bool {
	x = self.find(x)
	y = self.find(y)

	if x == y {
		return false
	}
	if x > y {
		x, y = y, x
	}
	self.parent[y] = x
	return true
}

func (self *DisjointSet) size() int {
	cnt := 0
	set := map[int]struct{}{}
	for i := 1; i < len(self.parent); i++ {
		v := self.find(i)
		if _, exists := set[v]; !exists {
			set[v] = struct{}{}
			cnt++
		}
	}
	return cnt
}

func main() {
	in.Split(bufio.ScanWords)
	defer out.Flush()

	N, M := nextInt(), nextInt()
	disjointSet := NewDisjointSet(N + 1)

	cnt := 0
	for i := 0; i < M; i++ {
		u, v := nextInt(), nextInt()
		if !disjointSet.union(u, v) {
			cnt++
		}
	}

	println(cnt + disjointSet.size() - 1)
}
