
# Sample script using the Zero module

include Zero

class MyTest < Test
  def initialize
	@update_count = 0
    self.print('MyTest Initialized')
  end
  
  def update
	puts "MyTest Update: #{@update_count+=1}"
  end
end

$testObj = MyTest.new

def update
  $testObj.update
end
