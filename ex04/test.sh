#!/bin/bash
echo "-- Test 01 --"
./sed tests/test01 "super
test" "beautiful example"
diff tests/test01.replace tests/test01.expected_replace

echo "-- Test 02 --"
./sed tests/test02 "apples" "fruits"
diff tests/test02.replace tests/test02.expected_replace

echo "-- Test 03 --"
./sed tests/test03 "not_found" "so bad"
diff tests/test03.replace tests/test03.expected_replace

echo "-- Test 04 --"
./sed tests/test04 "empty" "emptyy"
diff tests/test04.replace tests/test04.expected_replace

echo "-- Test 05 --"
echo "-- This test must show an error --"
./sed tests/test05 "" "pouet"

echo "-- Test 06 --"
./sed tests/test06 "pouet" ""
diff tests/test06.replace tests/test06.expected_replace

echo "-- Test 07 --"
echo "-- This test must show an error --"
./sed tests/test07 "" ""

echo "-- Test 08 --"
./sed tests/test08 "pouet" "pouetpouet"
diff tests/test08.replace tests/test08.expected_replace

echo "-- Test File not found --"
echo "-- This test must show an error --"
./sed tests/file_not_found "File not found" "dommage"

echo "-- Test No read perm --"
touch tests/no_perms
chmod 000 tests/no_perms
./sed tests/no_read_perm "coucou" "oui"

echo "-- Test open folder --"
./sed tests/ "coucou" "oui"
