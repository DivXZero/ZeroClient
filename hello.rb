
# Sample script using the Zero module

include Zero

class MyTest < Test
  attr_accessor :testvar

  def initialize
	@width = 800
	@window_options = { title: 'Test Window',
						width: 800,
						height: 600
						}
    #self.print('MyTest Initialized')
	self.create(@window_options)
	self.create(title: 'Test2', width: 640, height: 480)
  end
  
  def update
	#puts 'Update called!'
  end

end

testObj = MyTest.new

puts 'Random Numbers:'
nums = Array.new
$i = 0
while $i < 10 do
  nums.push(testObj.random(0, 100).to_i)
  $i += 1
end

print nums
puts

#puts "12 + 24 = #{testObj.add(12, 24)}"
#puts "Unset: #{testObj.testvar}"
#testObj.set()
#puts "Set: #{testObj.testvar}"
#puts "Width: #{testObj.getWidth()}"

#testObj2 = Test.new
#testObj2.print("12 + 12 = #{testObj2.add(12, 12)}")

#puts "Obj1 ID: #{testObj.getID}"
#puts "Obj2 ID: #{testObj2.getID}"