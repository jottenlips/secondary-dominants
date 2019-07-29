let getSecondaryDominantValue = halfStepFromKey => {
    switch (halfStepFromKey) { 
    | 0 => "I7"
    | 1 => "bII7"
    | 2 => "II7"
    | 3 => "bIII7"
    | 4 => "III7"
    | 5 => "IV7"
    | 6 => "bV7"
    | 7 => "V7"
    | 8 => "bVI7"
    | 9 => "VI7"
    | 10 => "bVII7"
    | 11 => "VII7"
    | _ => "I7"
    }
}

let getNoteIntValue = note => {
    switch (note) { 
    | "c" => 0
    | "db" | "c#" => 1
    | "d" => 2
    | "eb" | "d#" => 3
    | "e" => 4
    | "f" => 5
    | "gb" | "f#" => 6
    | "g" => 7
    | "ab" | "g#" => 8
    | "a" => 9
    | "bb" | "a#" => 10
    | "b" => 11
    | _ => 0
    }
}

let notes = [
    "c",
    "db",
    "d",
    "eb",
    "e",
    "f",
    "gb",
    "g",
    "ab",
    "a" ,
    "bb",
    "b"
]

/* let getExtensionNotationForHalfStep = halfStep => {
    switch (halfStep) {
    | 1 = "b9"
    | 2 => "9"
    | 3 => "#9"
    | 5 => "11"
    | 6 => "#11"
    | 8 => "b13"
    | 9 => "13"
    | _ => "0"
    }
} */

let flatToSharp = note => {
    switch (note) {
    | "db" => "c#"
    | "eb" => "d#"
    | "gb" => "f#"
    | "ab" => "g#"
    | "bb" => "a#"
    | _ => note
    }
}

let sharpToFlat = note => {
    switch (note) {
    | "c#" => "db"
    | "d#" => "eb"
    | "f#" => "gb"
    | "g#" => "ab" 
    | "a#" => "bb"
    | _ => note 
    }
}

let absoluteValue = number => (number < 0) ? number * -1 : number
let intervalDifference = (intervalA, intervalB) => absoluteValue(intervalA - intervalB);

let getChordPositionRelativeToKey = (~key, ~chordRoot) => {
    let lowercaseKey = String.lowercase(key)
    let lowercaseChordRoot = String.lowercase(chordRoot)
    let keyNoteValue = getNoteIntValue(lowercaseKey)
    let rootNoteValue = getNoteIntValue(lowercaseChordRoot)
    let intervalDifference = intervalDifference(rootNoteValue, keyNoteValue)
    let secondaryDominant = getSecondaryDominantValue(intervalDifference)
    Js.log(secondaryDominant)
}

getChordPositionRelativeToKey("a", "b")
