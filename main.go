package main

import "fmt"

const (
	rowPattern = "|%-20.20s|%-25.25s|%-30.30s|%-40.40s|\n"
)

func generateRow(comment string, format string, params ...interface{}) {
	output := fmt.Sprintf(format, params...)
	fmt.Printf(rowPattern,
		format,
		fmt.Sprintf("%v", params),
		fmt.Sprintf("`%s`", output),
		comment)
}

type S struct {
	a int
	b float32
}

func main() {
	// General
	obj := S{1, 3.14}
	generateRow("Generic value", "%v", obj)
	generateRow("Value with field names", "%+v", obj)
	generateRow("Go-syntax", "%#v", obj)
	generateRow("Go-syntax", "%T", obj)

	// Strings
	str := "Hello World!"
	generateRow("Quoted strings", "%q", str)
	generateRow("Spaced hexadecinal", "% x", "\xde\xad\xbe\xef")

	// Boolean
	generateRow("Boolean", "%t/%t", true, false)

	// Integers
	generateRow("Base 2", "%b", 127)
	generateRow("Singly quoted character literal", "%q", 127)

	// Slices
	slice := []string{"Hello", "World"}
	generateRow("Address of the first element in a slice", "%p", slice)

}
