Pod::Spec.new do |s|
  s.name         = 'RSDayFlow'
  s.version      = '0.4.0.1.1'
  s.summary      = 'iOS 7 Calendar with Infinite Scrolling.'
  s.homepage     = 'https://github.com/shiguol/RSDayFlow'
  s.source       = { :git => 'https://github.com/shiguol/RSDayFlow.git', :tag => '0.4.0.1.1' }
  s.platform     = :ios, '6.1'
  s.requires_arc = true
  s.source_files = 'RSDayFlow/*.{h,m}'
  s.frameworks = 'QuartzCore', 'UIKit'
end
