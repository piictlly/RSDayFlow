Pod::Spec.new do |s|
  s.name         = 'RSDayFlow'
  s.version      = '0.4.0.1.1'
  s.summary      = 'iOS 7 Calendar with Infinite Scrolling.'
  s.homepage     = 'https://github.com/piictlly/RSDayFlow'
  s.license       = { :type => 'MIT', :file => 'LICENSE' }
  s.authors       = { 'piictlly' => 'laoyong@weego.me' }
  s.source       = { :git => 'https://github.com/piictlly/RSDayFlow.git', :tag => s.version.to_s }
  s.platform     = :ios, '6.1'
  s.requires_arc = true
  s.source_files = 'RSDayFlow/*.{h,m}'
  s.frameworks = 'QuartzCore', 'UIKit'
end
