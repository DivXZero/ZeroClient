
# Sample script using the Zero module

include Zero

class MyTest < Test
  def initialize
	@update_count = 0
	@frame_switch = true
    @time = Time.now
  end
  
  def update
    @update_count+=1
	if((Time.now - @time) >= 1)
	  print "scn: #{self.scene_count}, ups: #{@update_count}             \r"
	  @update_count = 0
	  @time = Time.now
	  #frame_switch
	end
  end
  
  def frame_switch
    if @frame_switch
	  self.push_scene
	else
	  self.pop_scene
	end
    @frame_switch = !@frame_switch
  end
end

$testObj = MyTest.new

def update
  $testObj.update
end