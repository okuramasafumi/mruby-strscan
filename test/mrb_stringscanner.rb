##
## StringScanner Test
##

assert("StringScanner#hello") do
  t = StringScanner.new "hello"
  assert_equal("hello", t.hello)
end

assert("StringScanner#bye") do
  t = StringScanner.new "hello"
  assert_equal("hello bye", t.bye)
end

assert("StringScanner.hi") do
  assert_equal("hi!!", StringScanner.hi)
end
