package main

import (
	"crypto/sha256"
	"fmt"
	"math/rand"
	"strconv"

	//"encoding/json"
	"strings"
	"time"
)

var global int
var hashit string
var lastblockhashwithoutchange string
var lastblockhashwithchange string

type Block struct {
	transaction []*Transaction
	nounce      int
	prevhash    string
	currenthash string
}

type Transaction struct {
	TransactionID              string
	senderBlockchainAddress    string
	recipientBlockchainAddress string
	values                     float32
	timestamp                  int64
}

type Blockchain struct {
	list            []*Block
	transactionpool []*Transaction
}

func NewBlock(transaction []*Transaction) *Block {
	s := new(Block)
	s.transaction = transaction
	s.nounce = rand.Intn(10-2) + 2
	s.currenthash = CalculateHash(fmt.Sprint(transaction) + hashit + strconv.Itoa(s.nounce))
	lastblockhashwithoutchange = s.currenthash
	if global == 0 {
		hashit = s.currenthash
		global++
	} else if global >= 1 {
		s.prevhash = hashit
		hashit = s.currenthash
	}
	return s

}

func NewTransaction(sender string, recipient string, value float32) *Transaction {
	t := new(Transaction)
	t.senderBlockchainAddress = sender
	t.recipientBlockchainAddress = recipient
	t.values = value
	t.timestamp = time.Now().UnixNano()
	var strval string
	strval = fmt.Sprint(value)
	t.TransactionID = CalculateHash(strval + sender + recipient)

	return t

}

func (obj *Blockchain) createblock() *Block {

	as1 := NewBlock(obj.transactionpool)
	obj.list = append(obj.list, as1)
	return as1
}

func (obj *Blockchain) AddTransaction(sender string, recipient string, value float32) {
	transaction := NewTransaction(sender, recipient, value)
	obj.transactionpool = append(obj.transactionpool, transaction)
	//return transaction
}

func printblock(obj *Blockchain, blocknum int) {

	for i := 0; i < (len(obj.list)); i++ {

		fmt.Printf("%s Block %d %s\n", strings.Repeat("=", 25), i+1, strings.Repeat("=", 25))
		fmt.Println("Nounce: ", obj.list[blocknum].nounce)
		fmt.Println("Prev Hash: ", obj.list[blocknum].prevhash)
		for j := 0; j < len(obj.transactionpool); j++ {
			fmt.Printf("%s Transactions %d %s\n", strings.Repeat("-", 25), j+1, strings.Repeat("-", 25))
			fmt.Println("Sender Address:  ", obj.transactionpool[j].senderBlockchainAddress)
			fmt.Println("recipient Address:  ", obj.transactionpool[j].recipientBlockchainAddress)
			fmt.Println("Transaction Id:  ", obj.transactionpool[j].TransactionID)
			fmt.Println("Amount: ", obj.transactionpool[j].values)
			fmt.Println("Time:  ", obj.transactionpool[j].timestamp)
		}

	}

}

func CalculateHash(hashh string) string {

	return fmt.Sprintf("%x", sha256.Sum256([]byte(hashh)))
}

func main() {
	fmt.Printf("\n")
	fmt.Println("                       ---Welcome---                   ")
	fmt.Println("               Lets beign by creating blocks!            ")
	fmt.Printf("\n")
	s1 := new(Blockchain)

	s1.createblock()
	s1.AddTransaction("Alice", "Bob", 3.0)
	s1.AddTransaction("Bob", "Clice", 4.0)
	s1.AddTransaction("Alice", "Charlie", 2.0)
	s1.AddTransaction("Joe", "James", 1.0)
	s1.AddTransaction("Sam", "John", 5.0)
	s1.AddTransaction("Charlie", "Charlie", 2.0)
	s1.AddTransaction("Alice", "Sam", 3.0)
	s1.AddTransaction("Sam", "Bob", 5.0)
	s1.AddTransaction("Bob", "Lucy", 4.0)
	s1.AddTransaction("Charlie", "Norma", 2.0)
	printblock(s1, 0)
	s2 := new(Blockchain)
	s2.createblock()
	s2.AddTransaction("mama", "humna", 1.0)
	s2.AddTransaction("humza", "humna", 1.0)
	s2.AddTransaction("Alice", "Sam", 3.0)
	s2.AddTransaction("Sam", "Bob", 5.0)
	s2.AddTransaction("Bob", "Lucy", 4.0)
	s2.AddTransaction("Charlie", "Norma", 2.0)
	printblock(s2, 0)
	//fmt.Printf("\n")

	//printblock(s2, 0)

}
