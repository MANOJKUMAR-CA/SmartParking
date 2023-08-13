const emptySlots = document.getElementById("empty-slots");
const fullSlots = document.getElementById("full-slots");

let numEmptySlots = 3;
let numFullSlots = 2;

emptySlots.textContent = numEmptySlots;
fullSlots.textContent = numFullSlots;
function bookSlot() {
    var slotSelect = document.getElementById("slot-select");
    var selectedSlot = slotSelect.options[slotSelect.selectedIndex].value;
    var name = document.getElementById("name").value;
    var no=document.getElementById("no").value;
    
    if (name === "") {
      alert("Please enter your Vehicle Type");
      return;
    }
    if (no === "") {
      alert("Please enter your Vehicle Number");
      return;
    }
    var bookingStatus = document.getElementById("booking-status");
    bookingStatus.innerHTML = "Slot " + selectedSlot + " has been booked by " + no + ".";
  }
  