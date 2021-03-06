require File.dirname(File.join(__rhoGetCurrentDir(), __FILE__)) + '/../../spec_helper'
require File.dirname(File.join(__rhoGetCurrentDir(), __FILE__)) + '/fixtures/classes'
require File.dirname(File.join(__rhoGetCurrentDir(), __FILE__)) + '/shared/each'

describe "IO#each" do
  it_behaves_like(:io_each, :each)
end

describe "IO#each when passed a separator" do
  it_behaves_like :io_each_separator, :each_line
end
