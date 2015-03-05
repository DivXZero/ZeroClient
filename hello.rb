
# Sample script using the Zero module

include Zero

class MyTest < Test
  def initialize
	@update_count = 0
    #self.print('MyTest Initialized')
  end
  
  def update
    @update_count+=1
	$frameCount+=1
	if((Time.now - $time) >= 1)
	  print "#{$frameCount} updates per second.            \r"
	  $frameCount = 0;
	  $time = Time.now
	end
  end
end

$testObj = MyTest.new
$time = Time.now
$frameCount = 0

def update
  $testObj.update
end
