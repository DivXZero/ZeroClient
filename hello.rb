
# Sample script using the Zero module

include Zero

class MyTest < Test

  def initialize
    self.print('MyTest Initialized')
  end

end

testObj = MyTest.new

puts "12 + 24 = #{testObj.add(12, 24)}"