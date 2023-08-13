let slot1= 1;
let slot2=0 ;
let slot3= 0;
let slot4= 0;
let tot = 4;
let emp=0;
let fill=0;
function changeClass()
{
    if(slot1==1){
      document.getElementById("slot1").className = "booked";
      fill++; 
    }
    else{ 
    document.getElementById("slot1").className = "empty";
    emp++;}

    if(slot2==1){
      document.getElementById("slot2").className = "booked";
      fill++;}
    else{ 
    document.getElementById("slot2").className = "empty";
    emp++;}
    if(slot3==1){
      document.getElementById("slot3").className = "booked";
      fill++;}
    else{ 
    document.getElementById("slot3").className = "empty";
    emp++; }
    if(slot4==1)
      {
        document.getElementById("slot4").className = "booked";
        fill++;
    }
    else{ 
    document.getElementById("slot4").className = "empty";
    emp++;
    }

    document.getElementById("full-slots").textContent=fill;
    document.getElementById("empty-slots").textContent=emp;
    
}

