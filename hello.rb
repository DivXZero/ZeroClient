
# Sample script using the Zero module

include Zero

class MyTest < Test
  def initialize
	@update_count = 0
    @time = Time.now
  end
  
  def update
    @update_count+=1
	if((Time.now - @time) >= 1)
	  print "#{@update_count} updates per second.            \r"
	  @update_count = 0
	  @time = Time.now
	end
  end
end

$testObj = MyTest.new

def update
  $testObj.update
end