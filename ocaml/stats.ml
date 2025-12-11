(* stats.ml
   Functional version of mean, median, and mode.
   Uses lists, no mutation, no loops. *)

let mean lst =
  let total = List.fold_left ( + ) 0 lst in
  float_of_int total /. float_of_int (List.length lst)

let median lst =
  let sorted = List.sort compare lst in
  let n = List.length sorted in
  if n mod 2 = 1 then
    float_of_int (List.nth sorted (n / 2))
  else
    let a = List.nth sorted (n / 2 - 1) in
    let b = List.nth sorted (n / 2) in
    (float_of_int (a + b)) /. 2.0

let mode lst =
  (* Count frequencies using an assoc list *)
  let counts =
    List.fold_left
      (fun acc x ->
        let c = try List.assoc x acc with Not_found -> 0 in
        (x, c + 1) :: List.remove_assoc x acc)
      [] lst
  in
  fst (
    List.fold_left
      (fun (m_val, m_count) (v, c) ->
        if c > m_count then (v, c) else (m_val, m_count))
      (0, 0)
      counts
  )

let () =
  let data = [1; 2; 2; 3; 4; 5; 5; 5] in
  Printf.printf "Mean: %.2f\n" (mean data);
  Printf.printf "Median: %.2f\n" (median data);
  Printf.printf "Mode: %d\n" (mode data)
